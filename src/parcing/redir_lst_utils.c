/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:00:38 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/22 19:25:04 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

t_redir	*ft_lstnew_redir(char *name, int flag)
{
	t_redir	*node;

	node = malloc(sizeof(t_redir));
	if (!node)
		return (NULL);
    if (flag == 1)
    {
        node->fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        node->type = OUTPUT;
    }
    else if (flag == 2)
    {
        node->fd = open(name, O_WRONLY | O_CREAT | O_APPEND, 0644);
        node->type = APPEND;
    }
    else
    {
        node->fd = open(name, O_RDONLY);
        node->type = INPUT;
    }
	node->name = ft_strdup(name);
	node->next = NULL;
	return (node);
}

t_redir	*ft_lstlast_redir(t_redir *redir)
{
	if (!redir)
		return (NULL);
	while (redir->next != NULL)
		redir = redir->next;
	return (redir);
}

void ft_lstadd_back_redir(t_redir **redir, t_redir *new)
{
    t_redir *tmp;

    if (!new)
        return ;
    if (!redir || !(*redir))
    {
        *redir = new;
        return ;
    }
    tmp = ft_lstlast_redir(*redir);
    tmp->next = new;
}
