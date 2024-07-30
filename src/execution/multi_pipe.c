/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:25 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/30 13:33:41 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int    execute_cmd(t_list *list, t_data *data)
{
    if (list->next)
        if (pipe(list->pipe_fd) == -1)
            return (exit_func(PIPE_ERR, NULL), 1);
    if (list->infile > 0)
    {
        ft_putendl_fd("3ndi infile", STDERR_FILENO);
        dup2(list->infile, STDIN_FILENO);
        close(list->infile);
    }
    list->pid = fork_process();
    if (!list->pid)
    {
        if (list->infile == -1 || list->outfile == -1)
        {
            printf("hna\n");
            exit(1);
        }
        dup_out_pipe(list);
    write(2, "-----", 5);
    ft_putendl_fd(list->cmd_args[0], 2);
        if (is_builtins(list->cmd_args[0]))
            execute_builtins(data, list);
        else
            ft_execve(data);
    }
    dup2(list->pipe_fd[0], STDIN_FILENO);
    close_pipe(list);
    return (0);
}
