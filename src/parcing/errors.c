/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:13:31 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/15 15:19:24 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int print_error(t_data *data, char c)
{
    if (c == 's')
    {
        printf("synthax error\n");
        data->status = 1;
    }
    return (data->status);
}