/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:49:00 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/11 16:44:02 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void split_tokens(t_list **p_tokens)
{
    t_list *tmp;

    tmp = *p_tokens;
    while (tmp)
    {
        (tmp)->mini_tokens = ft_split((tmp)->content, ' ');
        tmp = (tmp)->next;
    }
}

//in this function i will fill the return of split into a linked list
void    ft_fill_tokens(char *cmd, t_list **p_tokens)
{
    char **str;
    t_list  *new;

    str = ft_split(cmd, '|');
    int i = -1;
    while (str[++i])
    {
        new = ft_lstnew(str[i]);
        ft_lstadd_back(p_tokens, new);
        free(str[i]);
    }
    free(str);
    return_pipe(p_tokens);
}

void    return_pipe(t_list **p_tokens)
{
    int i;
    t_list  *tmp;

    tmp = *p_tokens;
    while (tmp)
    {
        i = -1;
        while (tmp->content[++i])
            if ((tmp->content[i] * (-1)) == '|')
                tmp->content[i] *= (-1);       
        tmp = tmp->next;
    }
}