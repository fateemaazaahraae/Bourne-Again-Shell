/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:54:23 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/21 10:48:53 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

// void ft_lstdelone(t_list *lst, void (*del)(void*))
// {
//     if (lst && del)
//     {
//         del(lst->content);
//         free(lst);
//     }
// }

void ft_lstclear2(t_list **lst)
{
    t_list *temp;

    if (!lst)
        return;

    while (*lst)
    {
        temp = (*lst)->next;
        free((*lst)->content);
        free(*lst);
        // ft_lstdelone(*lst, del);
        *lst = temp;
    }
    *lst = NULL;
}

void free_2D(char **str)
{
    int i;

    i = -1;
    while (str[++i])
        free(str[i]);
    free(str[i]);
}

void    ft_free_struct(t_data **data)
{
    while ((*data)->list)
    {
        free_2D((*data)->list->mini_tokens);
        (*data)->list = (*data)->list->next;
    }
    ft_lstclear2(&((*data)->list));
}