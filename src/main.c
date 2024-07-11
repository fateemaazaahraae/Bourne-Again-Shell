/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/11 11:45:01 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    char *str;
   t_env *my_env;
    (void)ac;
    (void)av;
    (void)my_env;
    (void)env;
    //my_env = get_env(env);
    while (1)
    {
        str = readline("\x1b[32mminishell $> \x1b[0m");
        solve_pipe_problem(str);
        ft_fill_tokens(str);
        //return_pipe()
    }
}