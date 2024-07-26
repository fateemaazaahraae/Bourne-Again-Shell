/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:25 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/26 12:50:41 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void handle_child_process(t_data *data)
{
    ft_execve(data);
    exit(EXIT_SUCCESS);
}

void execute_cmd(t_data *data, t_list *list, int fd_in, int *pipe_fd)
{
    pid_t pid;

    red_in_out(list, pipe_fd, fd_in);
    if (is_builtins(list->cmd_args[0]))
        execute_builtins(data, list);
    else
    {
        pid = fork();
        if (pid == 0)
            handle_child_process(data);
    }
}
