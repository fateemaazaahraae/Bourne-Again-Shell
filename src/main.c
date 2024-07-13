/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/13 11:19:42 by aakouhar         ###   ########.fr       */
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
    // int i;
// ls -la>"he was fun"|cat "he was fun" -----> ls    -la  >|   he was fun  |   cat  he was fun
    p_tokens = NULL;
    //my_env = get_env(env);
    while (1)
    {
        str = readline("\x1b[32mminishell $> \x1b[0m");
        // solve_pipe_problem(str);
        ft_fill_tokens(str, &p_tokens);
        // split_tokens(&p_tokens); //this function is for spliting tokens by space this time not by pipe
        while (p_tokens)
        {
            printf("token --> %s\n", p_tokens->content);
            p_tokens = p_tokens->next;
        }
    }
}
