/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:11:04 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/20 18:42:48 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

void    pwd(t_env *env)
{
    char pwd[1000];
    // while (env)
    // {
    //     if (!ft_strcmp(env->key, "PWD"))
    //     {
    //         printf("%s\n", env->value);
    //         return ;
    //     }
    //     env = env->next;
    // }
    if (getcwd(pwd, sizeof(pwd)))
        printf("%s\n", pwd);
    else
        perror("getcwd");
}