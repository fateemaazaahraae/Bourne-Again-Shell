/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:49:00 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/25 12:37:44 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

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

void fill_mini_tokens(t_data *data)
{
    t_list *tmp;

    tmp = data->list;
    while (tmp)
    {
        tmp->mini_tokens = ft_split(tmp->content, ' ');
        tmp->out = NULL;
        tmp->in = NULL;
        tmp->limiter = NULL;
        tmp = tmp->next;
    }
}

void    ft_fill_tokens(t_data *data)
{
    char **str;
    t_list  *new;

    str = ft_split(data->cmd, '|');
    data->list = NULL;
    int i = -1;
    while (str[++i])
    {
        new = ft_lstnew(str[i]);
        ft_lstadd_back(&data->list, new);
        free(str[i]);
    }
    free(str);
    // return_pipe(data);
    fill_mini_tokens(data);
    return_special_char(data);
    fill_cmd_args(data);
}
