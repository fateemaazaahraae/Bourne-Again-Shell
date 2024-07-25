/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:37:08 by tiima             #+#    #+#             */
/*   Updated: 2024/07/18 13:25:52 by fbazaz           ###   ########.fr       */
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

int is_n_flag(char *arg)
{
    int j = 1;
    if (arg[0] != '-')
        return (0);
    while (arg[j]) {
        if (arg[j] != 'n')
            return (0);
        j++;
    }
    return (1);
}

int echo(char **args)
{
    int i;
    int n_flag;
    
    i = 1;
    n_flag = 0;
    while (args[i] && is_n_flag(args[i]))
    {
        n_flag = 1;
        i++;
    }
    while (args[i])
    {
        printf("%s", args[i]);
        if (args[i + 1])
            printf(" ");
        i++;
    }
    if (!n_flag)
        printf("\n");
    return 0;
}

