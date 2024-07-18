/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:37:08 by tiima             #+#    #+#             */
/*   Updated: 2024/07/17 17:57:26 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

int nb_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
        i++;
    return (i);
}

int echo(char **args)
{
    int i;
    int n_flag;

    n_flag = 1;
    i = 1;
    // printf("hello\n");
    if (nb_args(args) > 1)
    {
        if (args[i] && !ft_strcmp(args[i], "-n"))
        {
            i++;
            n_flag = 0;
        }
        while (args[i])
        {
            printf("%s", args[i]);
            if (args[i + 1])
                printf(" ");
            i++;
        }
    }
    if (n_flag)
        printf("\n");
    return (0);
}
