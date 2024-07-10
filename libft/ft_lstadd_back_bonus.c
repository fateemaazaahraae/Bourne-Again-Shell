/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:09:06 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/10 11:59:15 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*p;

// 	if (*lst)
// 	{
// 		p = ft_lstlast(*lst);
// 		p->next = new;
// 	}
// 	else
// 		*lst = new;
// }turn (lst);


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