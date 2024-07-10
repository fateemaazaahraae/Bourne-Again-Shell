/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:01:38 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/10 10:36:02 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//in this function i check if there is any pipe into a ' or " and multiple it in -1 andd check for synthax error
void    solve_pipe_problem(char *str)
{
    int i;
    bool d_quate;
    bool s_quate;

    i = -1;
    d_quate = false;
    s_quate = false;
    while (str[++i])
    {
        if (str[i] == '\"' && d_quate == false)
            d_quate = true;
        if (str[i] == '\"' && d_quate == true)  
            d_quate = false;
        if (str[i] == '\'' && s_quate == false)
            s_quate = true;
        if (str[i] == '\'' && s_quate == true)  
            s_quate = false;
        if (str[i] == '|' && (s_quate == true || d_quate == true))
            str[i] *= -1;
        if (str[i] == '|' && str[i + 1] == '|' && s_quate == false && d_quate == false)
            print_error('s');
        check_synthax_error(str[i]);
    }
}
   
//check for simple synthax error
void check_synthax_error(char c)
{
    int i;

    char *check;

    check = "&()`/,;[]*";
    i = -1;
    while (check[++i])
    {
        if (c == check[i])
            print_error('s');
    }
}