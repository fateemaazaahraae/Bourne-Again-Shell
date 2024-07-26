/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:16:28 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/26 17:23:07 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

// void    execute_one(t_data *data)
// {
//     int pid;
//     int saved_stdin;
//     int saved_stdout;

//     // if (data->list->limiter)
//     //     here_doc(data->list);
//     if (is_builtins(data->list->cmd_args[0]))
//     {
//         red_in_out(data->list, &saved_stdin, &saved_stdout);
//         execute_builtins(data, data->list);
//         restore_stdio(saved_stdin, saved_stdout);
//     }
//     else
//     {
//         pid = fork_process();
//         if (pid == 0)
//         {
//             red_in_out(data->list, &saved_stdin, &saved_stdout);
//             ft_execve(data);
//         }
//         else
//             wait(NULL);
//     }
// }

// void execute(t_data *data)
// {
//     int pipe_fd[2];
//     int fd_in;

//     fd_in = 0;
//     if (ft_lstsize(data->list) == 1)
//         execute_one(data);
//     else
//         while (data->list)
//         {
//             if (data->list->limiter)
//                 here_doc(data->list);
//             if (data->list->next)
//                 open_pipes(pipe_fd);
//             execute_cmd(data, data->list, pipe_fd, fd_in);
//             if (data->list->next)
//             {
//                 close(pipe_fd[1]);
//                 if (fd_in != 0)
//                     close(fd_in);
//             }
//             fd_in = pipe_fd[0];
//             wait(NULL);
//             data->list = data->list->next;
//         }
// }

void execute(t_data *data)
{
    int pipe_fd[2];
    int fd_in;
    int saved_stdin;
    int saved_stdout;

    fd_in = 0;
    save_stdio(&saved_stdin, &saved_stdout);
    while (data->list)
    {
        if (data->list->next)
            open_pipes(pipe_fd);
        // printf("psps %i // %i\n", pipe_fd[0], pipe_fd[1]);
        execute_cmd(data, data->list, fd_in, pipe_fd);
        if (data->list->next)
        {
            close(pipe_fd[1]);
            if (fd_in != 0)
                close(fd_in);
        }
        // if (pipe_fd[0])
        fd_in = pipe_fd[0];
        data->list = data->list->next;
    }
    while (wait(NULL) > 0);
    restore_stdio(saved_stdin, saved_stdout);
}
