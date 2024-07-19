/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:09:06 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/16 14:53:33 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * void ft_lstadd_back - Adds the node ’new’ at the end of the list.
 * @lst: The address of a pointer to the first link of a list.
 * @new: The address of a pointer to the node to be added to the list.
 *
 * Return: void.
 */

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *tmp;

    if (!new)
        return ;
    if (!lst || !(*lst))
    {
        *lst = new;
        return ;
    }
    tmp = ft_lstlast(*lst);
    tmp->next = new;
}
