/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:28:11 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/07/20 09:49:13 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/minishell.h"

void    remove_invalide_quote(t_data *data)
{
    int i;

    i = -1;
    while (++i)
    {
        if (data->cmd[i] == '\"' && data->cmd[i - 1] != ' '){}
    }
}

int ft_parcing(t_data *data)
{
    solve_pipe_problem(data->cmd);
    if(check_synthax_error(data->cmd) || check_quote(data))
        return (data->status);
    remove_invalid_quote(data);
} // l"s"