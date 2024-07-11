/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/11 16:40:24 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    char *str;
    t_list *p_tokens;
   t_env *my_env;
    (void)ac;
    (void)av;
    (void)my_env;
    (void)env;
    int i;

    p_tokens = NULL;
    //my_env = get_env(env);
    while (1)
    {
        str = readline("\x1b[32mminishell $> \x1b[0m");
        solve_pipe_problem(str);
        ft_fill_tokens(str, &p_tokens);
        split_tokens(&p_tokens); //this function is for spliting tokens by space this time not by pipe
        while (p_tokens)
        {
            i = -1;
            printf("token --> %s\n", p_tokens->content);
            while (p_tokens->mini_tokens[++i])
                printf("mini ---> %s\n", p_tokens->mini_tokens[i]);
            p_tokens = p_tokens->next;
        }
    }
}
