/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/08 19:48:24 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    // char *str;
    t_env *my_env;
    (void)ac;
    (void)av;

    my_env = get_env(env);
    printf("key: %s && value: %s\n", my_env->key, my_env->value);
    // while (1)
    // {
    //     str = readline("\x1b[32mminishell $> \x1b[0m");
    //     printf("%s\n", str);
    // }
}