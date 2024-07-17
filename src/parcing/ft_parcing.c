/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:28:11 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/07/16 12:01:21 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/minishell.h"

void    remove_invalide_quote(t_data *data)
{
    int i;

    i = -1;
    while (++i)
    {
        if (data->cmd[i] == '\"' && data->cmd[i - 1] != ' ')
    }
}

int ft_parcing(t_data *data)
{
    solve_pipe_problem(data->cmd);
    if(check_synthax_error(data->cmd) || check_quote(data))
        return (data->status);
    remove_invalid_quote(data);
} // l"s"