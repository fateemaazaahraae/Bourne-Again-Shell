/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:28:11 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/07/08 20:17:30 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/minishell.h"

void first_check(char *line)
{
    bool    d_quote;
    bool    s_quote;

    d_quote = false;
    s_quote = false;
    int i;
    
    i = -1;
    while (line[++i])
    {
        if (line[i] == '\"')
            d_quote = true;
        else if (line[i] == '\'')
            s_quote = true;
        if (line[i] == '\'')
            
        if ((line[i] == '|' || line[i] == '>') && (s_quote == true || d_quote == true))
            line[i] *= -1;
    }
    if (s_quote ==true || d_quote == true)
        print_error('s');
}