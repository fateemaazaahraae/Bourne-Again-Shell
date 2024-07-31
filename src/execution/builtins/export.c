/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:28:02 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/31 13:06:06 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

void    export(char **args)
{
    // t_env *new;
    t_env *env;
    // char *str;
    int i;

    i = 0;
    env = global_data->my_env;
    if (!args[1])
    {
        print_sorted_env(env);
        return ;
    }
    while (args[++i])
    {
        if (args[i] && args[i][0] != '_' && !ft_isalpha(args[i][0]))
        {
            global_data->exit_status = 1;
            exit_func(EXPORT_ERR, args[i]);
            continue;
        }
        // if (args[i])
        //     lst_addexport();
    }
}
