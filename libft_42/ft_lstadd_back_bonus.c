/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:09:06 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/21 16:08:40 by fbazaz           ###   ########.fr       */
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (*lst)
	{
		p = ft_lstlast(*lst);
		p->next = new;
	}
	else
		*lst = new;
}
