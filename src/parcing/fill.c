 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:49:00 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/13 12:02:27 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

/* void split_tokens(t_list **p_tokens)
{
    t_list *tmp;

    tmp = *p_tokens;
    while (tmp)
    {
        (tmp)->mini_tokens = ft_split((tmp)->content, ' ');
        tmp = (tmp)->next;
    }
} */

//in this function i will fill the return of split into a linked list
/* void    ft_fill_tokens(char *cmd, t_list **p_tokens)
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
} */
// int ft_fill_tokens(t_list **p_tokens, char *str) // "'hello'"
// {
//     int i;
//     int start;
//     int end;
//     int flag;
//     t_list *new;

//     i = -1;
//     end = 0;
//     while (str[++i])
//     {
//         start = end;
//         if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') // ls -la 
//             end = i;
//         else if (str[i] == '>' || '<')
//         {
//             end = i;
//         }
//         else if (str[i] == '\"' || str[i] == '\'')
//         {
//             start = i;
//             end = reach_end_of_quote(str, i);
//         }
//         start = i;
//         new = ft_lstnew(ft_substr(str, start, end));
//         ft_lstadd_back(p_tokens, new);
//    }
//    return (0);
// }


// int reach_end_of_quote(char *str, int index)
// {
//     int i;
//     char c;
    
//     i = index - 1;
//     if (str[index] == '\'')
//         c = '\''; //""'hello'""
//     else
//         c = '\"';
//     while (str[++i])
//     {
//         if (str[i] == c)
//             return (i);
//     }
//     return (-1);
// }


static void fill_mini_tokens(t_data *data)
{
    t_list *tmp;

    tmp = data->list;
    while (tmp)
    {
        tmp->mini_tokens = ft_split(tmp->content, ' ');
        tmp = tmp->next;
    }
}

void    ft_fill_tokens(t_data *data)
{
    char **str;
    t_list  *new;

    str = ft_split(data->cmd, '|');
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
}