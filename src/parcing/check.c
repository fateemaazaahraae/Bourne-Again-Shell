/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:01:38 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/11 16:42:53 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//in this function i check if there is any pipe into a ' or " and multiple it in -1 andd check for synthax error
void    solve_pipe_problem(char *str)
{
    int i;
    bool d_quote;
    bool s_quote;

    i = -1;
    d_quote = false;
    s_quote = false;
    while (str[++i])
    { 
        if (str[i] == '\"')
            d_quote = !d_quote;
        else if (str[i] == '\'')
            s_quote = !s_quote;
        else if (str[i] == '|' && (s_quote || d_quote))
            str[i] *= -1;
        else if (str[i] == '|' && str[i + 1] == '|' && !s_quote && !d_quote)
            return (print_error('s'));
    }
    if (s_quote == true || d_quote == true)
        return (print_error('s'));
    check_synthax_error(str);
}
   
//check for simple synthax error
void check_synthax_error(char *str)
{
    int i;
    int j;
    char *check;

    check = "&()`/,;[]*";
    i = -1;
    while (str[++i])
    {
        j = -1;
        while (check[++j])
            if (str[i] == check[j])
                return (print_error('s'));
    }
    check_pipe(str, "&()`/,;[]*><");
}

int is_all_space(char *str)
{
    int i;

    i = 1;
    while (str[i] == ' ')
        i++;
    if (str[i])
        return (1);
    return (0);
}

//check if the pipe in the begin or the end
void    check_pipe(char *str, char *check)
{
    int i;
    int j;

    i = -1;
    while (str[++i])
    {
        if (str[i] == '|' && (i == 0 || !str[i + 1] || !is_all_space(str + i)))
            return (print_error('s'));
        if (str[i] == '|')
        {
            while (str[i + 1] == ' ')
                i++;
            j = -1;
            while (check[++j])
                if (str[i + 1] == check[j])
                     return (print_error('s'));
        }
    }
}
