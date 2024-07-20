/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:25 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/20 17:20:46 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

// void    dup_fd(t_data *data, int index)
// {
//     if (index == 0)
//     {
//         dup2(data->fd[1], 1);
//         close(data->fd[1]);
//     }
//     else if (index == 2)
//     {
//         dup2(data->fd[0], 0);
//         close(data->fd[0]);
//         dup2(data->fd[1], 1);
//         close(data->fd[1]);
//     }
//     else
//     {
//         dup2(data->fd[0], 0);
//         close(data->fd[0]);
//     }
// }

// void    execute_non_builtins(t_data *data, int index)
// {
//     int pid;

//     if (pipe(data->fd) == -1)
//         perror("pipe");
//     pid = fork();
//     if (pid == 0)
//     {
//         // dup_fd(data, index);
//         ft_execve(data);
//     }
//     else
//         wait(NULL);
// }

void handle_child_process(t_data *data, int fd_in, int pipe_fd[2])
{
    if (fd_in != 0)
    {
        dup2(fd_in, 0);
        close(fd_in);
    }
    if (data->list->next)
    {
        dup2(pipe_fd[1], 1);
        close(pipe_fd[1]);
    }
    if (is_builtins(data->list->mini_tokens[0]))
        execute_builtins(data);
    else
        ft_execve(data);
    exit(EXIT_SUCCESS);
}
