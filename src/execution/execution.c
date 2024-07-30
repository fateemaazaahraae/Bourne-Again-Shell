/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:16:28 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/26 09:05:14 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

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

void execute(t_data *data)
{
    int pipe_fd[2];
    pid_t pid;
    int fd_in = 0;

    while (data->list)
    {
        if (data->list->limiter)
            here_doc(data->list);
        if (data->list->next)
            open_pipes(pipe_fd);
        if (is_builtins(data->list->cmd_args[0]))
        {
            // redirection(data->list, pipe_fd);
            execute_builtins(data, data->list);
        }
        else
        {
            pid = fork_process();
            if (pid == 0)
                handle_child_process(data, data->list, fd_in, pipe_fd);
        }
        if (data->list->next)
        {
            close(pipe_fd[1]);
            if (fd_in != 0)
                close(fd_in);
        }
        fd_in = pipe_fd[0];
        wait(NULL);
        data->list = data->list->next;
    }
}

