/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/08 18:09:59 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    char *str;
    (void)ac;
    (void)av;
    (void)env;

    /* while (*env)
    {
        printf("%s\n", *env);
        env++;
    } */
    while (1)
    {
        str = readline("\x1b[32mminishell $> \x1b[0m");
        printf("%s\n", str);
    }
}