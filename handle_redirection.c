void handle_redirection(t_data *data) {
    int fd;

    for (t_redirection *redir = data->list->redirections; redir != NULL; redir = redir->next) {
        if (redir->type == REDIR_INPUT) {
            fd = open(redir->file, O_RDONLY);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
        } else if (redir->type == REDIR_OUTPUT) {
            fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        } else if (redir->type == REDIR_APPEND) {
            fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
    }
}

void execute_builtins(t_data *data, int fd_in, int pipe_fd[2]) {
    if (fd_in != 0) {
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);
    }
    if (data->list->next) {
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);
    }
    handle_redirection(data);

    if (ft_strcmp(data->list->mini_tokens[0], "cd") == 0)
        cd(data->list->mini_tokens, data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "echo") == 0)
        echo(data->list->mini_tokens);
    else if (ft_strcmp(data->list->mini_tokens[0], "pwd") == 0)
        pwd(data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "export") == 0)
        export(data->list->mini_tokens, data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "unset") == 0)
        unset(data->list->mini_tokens, data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "env") == 0)
        env(data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "exit") == 0)
        exit(0);
}


void execute(t_data *data) {
    int pipe_fd[2];
    pid_t pid;
    int fd_in = 0;

    while (data->list) {
        if (data->list->next)
            open_pipes(pipe_fd);

        if (is_builtins(data->list->mini_tokens[0])) {
            int saved_stdin = dup(STDIN_FILENO);
            int saved_stdout = dup(STDOUT_FILENO);

            handle_redirection(data);
            execute_builtins(data, fd_in, pipe_fd);

            dup2(saved_stdin, STDIN_FILENO);
            dup2(saved_stdout, STDOUT_FILENO);
            close(saved_stdin);
            close(saved_stdout);
        } else {
            pid = fork_process();
            if (pid == 0)
                handle_child_process(data, fd_in, pipe_fd);
        }

        if (data->list->next)
            close(pipe_fd[1]);
        fd_in = pipe_fd[0];
        data->list = data->list->next;
        wait(NULL);
    }
}

