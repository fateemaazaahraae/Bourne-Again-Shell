/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:40:55 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/20 19:02:17 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

void    update_old_pwd(t_env *env)
{
    char o_pwd[1000];

    while (env)
    {
        if (!ft_strcmp(env->key, "OLDPWD"))
        {
            if (getcwd(o_pwd, sizeof(o_pwd)))
            {
                free(env->value);
                env->value = ft_strdup(o_pwd);
            }
                // ft_strcpy(env->value, o_pwd);
            else
                perror("getcwd");
            // printf(">> old_pwd: %s\n\n", env->value);
            return ;
        }
        env = env->next;
    }
}

void    update_pwd(t_env *env)
{
    char pwd[1000];

    while (env)
    {
        if (!ft_strcmp(env->key, "PWD"))
        {
            if (getcwd(pwd, sizeof(pwd)))
            {
                free(env->value);
                env->value = ft_strdup(pwd);
            }
                // ft_strcpy(env->value, pwd);
            else
                perror("getcwd");
            // printf(">> pwd: %s\n\n", env->value);
            return ;
        }
        env = env->next;
    }
}

void    go_to_home(t_env *env)
{
    while (env)
    {
        if (!ft_strcmp(env->key, "HOME"))
        {
            if (chdir(env->value))
                perror("cd");
            return ;
        }
        env = env->next;
    }
}

void    cd(char **args, t_env *env)
{
    update_old_pwd(env);
    if (!args[1] || !ft_strcmp(args[1], "~"))
        go_to_home(env);
    else 
        if (chdir(args[1]))
            perror("cd");
    update_pwd(env);
}

