/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:25 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/29 19:24:52 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void handle_child_process(t_data *data)
{
    ft_execve(data);
    exit(EXIT_SUCCESS);
}

void execute_cmd(t_data *data, t_list *list, int *fd_in)
{
    pid_t   pid;
    int     pipe_fd[2];
    t_redir *in;

    in = NULL;
    in = ft_lstlast_redir(list->in);
    if (in && in->fd > 0)
    {
        dup2(in->fd, 0);
        close(in->fd);
    }
    if (data->list->next)
        open_pipes(pipe_fd);
    if (is_builtins(list->cmd_args[0]))
    {
        red_in_out(list, pipe_fd, *fd_in);
        execute_builtins(data, list);
    }
    else
    {
        pid = fork_process();
        if (pid == 0)
        {
            // write(2, "----------------------------\n", 29);
            red_in_out(list, pipe_fd, *fd_in);
            handle_child_process(data);
            close(pipe_fd[0]);
            close(pipe_fd[1]);
        }
        else
        {
            close_pipe(pipe_fd);
        }
    }
	dup2(pipe_fd[0], 0);
}
