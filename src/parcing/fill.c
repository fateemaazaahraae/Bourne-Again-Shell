/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:49:00 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/11 10:32:40 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

//in this function i will fill the return of split into a linked list
void    ft_fill_tokens(char *cmd)
{
    char **str;
    t_list *p_tokens;
    t_list  *new;

    str = ft_split(cmd, '|');
    int i = -1;
    p_tokens = NULL;
    while (str[++i])
    {
        new = ft_lstnew(str[i]);
        ft_lstadd_back(&p_tokens, new);
        free(str[i]);
    }
/*     while (p_tokens)
    {
        printf("%s\n", p_tokens->content);
        p_tokens = p_tokens->next;
    } */
    free(str);
    split_tokens(p_tokens); //this function is for spliting tokens by space this time not by pipe
    
    
}