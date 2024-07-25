/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:08:12 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/24 15:49:26 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void    redirection(t_list *list, int *pipe_fd)
{
    t_redir *in;
    t_redir *out;

    in = ft_lstlast_redir(list->in);
    out = ft_lstlast_redir(list->out);
    if (in)
    {
        dup2(in->fd, 0);
        close(in->fd);
    }
    else if (pipe_fd && pipe_fd[0] != -1)
    {
        dup2(pipe_fd[0], 0);
        close(pipe_fd[0]);
    }
    if (out)
    {
        dup2(out->fd, 1);
        close(out->fd);
    }
    else if (pipe_fd && pipe_fd[1] != -1)
    {
        dup2(pipe_fd[1], 1);
        close(pipe_fd[1]);
    }
}
