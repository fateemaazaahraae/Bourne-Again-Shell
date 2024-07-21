# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "includes/env.h"
// # include "includes/execution.h"

typedef enum e_redir_type {
    REDIR_INPUT,   // <
    REDIR_OUTPUT,  // >
    REDIR_APPEND   // >>
} t_redir_type;

typedef struct s_redirection {
    t_redir_type type;          // The type of redirection
    char *file;                 // The file involved in the redirection
    struct s_redirection *next; // Pointer to the next redirection in the list
} t_redirection;

typedef struct s_list {
    char **mini_tokens;         // The parsed command tokens
    t_redirection *redirections; // The linked list of redirections
    struct s_list *next;        // Pointer to the next command in the pipeline
} t_list;

typedef struct s_data
{
    t_list  *list;
    t_env   *my_env;
    char    *cmd;
    char    *new_cmd;
    int     status;
    bool    d_quote;
    bool    s_quote;
    int     fd[2];
} t_data;


// typedef struct s_data {
//     t_list *list;             // The list of commands
//     t_env *my_env;            // The environment variables
//     char *cmd;                // The raw command string
// } t_data;


char	**ft_split(char const *s, char c);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int is_builtins(char *command);
void    execute_builtins(t_data *data);

char *get_cmd_path(char *cmd, char **paths)
{
    int i;
    char *cmd_path;

    if (!cmd || !paths)
        return (NULL);
    i = -1;
    while (paths[++i])
    {
        cmd_path = ft_strjoin(paths[i], "/");
        cmd_path = ft_strjoin(cmd_path, cmd);
        if (!access(cmd_path, X_OK))
            return (cmd_path);
        free(cmd_path);
    }
    return (NULL);
}

char *find_path(t_env *my_env)
{
    t_env *env;

    env = my_env;
    while (env)
    {
        if (!ft_strcmp(env->key, "PATH"))
            return (ft_strdup(env->value));
        env = env->next;
    }
    return (NULL);
}

void    ft_execve(t_data *data)
{
    char *all_path;
    char **paths;
    char *cmd_path;

    all_path = find_path(data->my_env);
    paths = ft_split(all_path, ':');
    cmd_path = get_cmd_path(data->list->mini_tokens[0], paths);
    if (!cmd_path)
    {
        printf("minishelllll: %s: command not found\n", data->list->mini_tokens[0]);
        exit (127);
    }
    // for (int i = 0; data->list->mini_tokens[i]; i++)
    //     printf("--> %s\n", data->list->mini_tokens[i]);
    if (execve(cmd_path, data->list->mini_tokens, env_to_2D(data->my_env)))
        perror("execve");
}

int init_program(t_data **data, char **envp)
{
    *data = malloc(sizeof(t_data));
    if (!(*data))
        return (printf("Failed to allocate memory for data\n"));
    (*data)->list = malloc(sizeof(t_list));
    if (!(*data)->list)
        return (free(*data), printf("Failed to allocate memory for data->list\n"));
    (*data)->list = NULL;
    (*data)->my_env = get_env(envp);
    return (0);
}

void    open_pipes(int *pipe_fd)
{
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

pid_t    fork_process()
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return (pid);
}

void add_redirection(t_redirection **redir_list, t_redir_type type, char *file) {
    t_redirection *new_redir = malloc(sizeof(t_redirection));
    if (!new_redir)
        return;

    new_redir->type = type;
    new_redir->file = strdup(file); // Allocate and copy the file name
    new_redir->next = *redir_list;
    *redir_list = new_redir;
}

void parse_command(char *cmd, t_data *data) {
    char **commands = ft_split(cmd, '|'); // Split by pipes
    t_list *prev = NULL;

    for (int i = 0; commands[i]; i++) {
        t_list *new_node = malloc(sizeof(t_list));
        if (!new_node)
            return;

        new_node->mini_tokens = ft_split(commands[i], ' '); // Split by spaces for tokens
        new_node->redirections = NULL;
        new_node->next = NULL;

        // Parse redirections
        for (int j = 0; new_node->mini_tokens[j]; j++) {
            if (strcmp(new_node->mini_tokens[j], ">") == 0) {
                add_redirection(&new_node->redirections, REDIR_OUTPUT, new_node->mini_tokens[j + 1]);
                free(new_node->mini_tokens[j]);
                free(new_node->mini_tokens[j + 1]);
                new_node->mini_tokens[j] = NULL;
                new_node->mini_tokens[j + 1] = NULL;
            } else if (strcmp(new_node->mini_tokens[j], ">>") == 0) {
                add_redirection(&new_node->redirections, REDIR_APPEND, new_node->mini_tokens[j + 1]);
                free(new_node->mini_tokens[j]);
                free(new_node->mini_tokens[j + 1]);
                new_node->mini_tokens[j] = NULL;
                new_node->mini_tokens[j + 1] = NULL;
            } else if (strcmp(new_node->mini_tokens[j], "<") == 0) {
                add_redirection(&new_node->redirections, REDIR_INPUT, new_node->mini_tokens[j + 1]);
                free(new_node->mini_tokens[j]);
                free(new_node->mini_tokens[j + 1]);
                new_node->mini_tokens[j] = NULL;
                new_node->mini_tokens[j + 1] = NULL;
            }
        }

        // Link nodes
        if (prev)
            prev->next = new_node;
        else
            data->list = new_node;

        prev = new_node;
    }
    free(commands);
}



void handle_redirection(t_redirection *redirections) {
    int fd;

    while (redirections) {
        if (redirections->type == REDIR_INPUT) {
            fd = open(redirections->file, O_RDONLY);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
        } else if (redirections->type == REDIR_OUTPUT) {
            fd = open(redirections->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        } else if (redirections->type == REDIR_APPEND) {
            fd = open(redirections->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
        }
        redirections = redirections->next;
    }
}

void handle_child_process(t_data *data, int fd_in, int pipe_fd[2]) {
    if (fd_in != 0) {
        dup2(fd_in, STDIN_FILENO);
        close(fd_in);
    }
    if (data->list->next) {
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);
    }
    handle_redirection(data->list->redirections);
    ft_execve(data);
    exit(EXIT_SUCCESS);
}

void execute(t_data *data) {
    int pipe_fd[2];
    pid_t pid;
    int fd_in = 0;

    while (data->list) {
        if (data->list->next)
            open_pipes(pipe_fd);
        if (is_builtins(data->list->mini_tokens[0]))
            execute_builtins(data);
        else {
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


int main(int ac, char **av, char **envp) {
    t_data *data;
    (void)ac;
    (void)av;

    if (init_program(&data, envp))
        return (1);
    while (1) {
        data->cmd = readline("\x1b[32mminishell $> \x1b[0m");
        add_history(data->cmd);
        parse_command(data->cmd, data);
        execute(data);
        ft_free_struct(&data);
    }
}
