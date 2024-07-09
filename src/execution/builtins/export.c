/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:28:02 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/09 18:46:13 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

void    export(char **args, t_env *env)
{
    t_env *new;
    char *str;
    int i;

    i = 1;
    while (args[i])
    {
        str = ft_strchr(args[i], '=');
        if (str)
        {
            *str = '\0';
            new = ft_lstnew2(args[i], str + 1);
            *str = '=';
            ft_lstadd_back2(&env, new);
        }
        i++;
    }
}