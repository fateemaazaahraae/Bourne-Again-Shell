/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/16 14:26:04 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    t_data *data;
    (void)ac;
    (void)av;
    // int i;
// ls -la>"he was fun"|cat "he was fun" -----> ls    -la  >|   he was fun  |   cat  he was fun
    data = NULL;
    data->my_env = get_env(env);
    while (1)
    {
        data->cmd = readline("\x1b[32mminishell $> \x1b[0m");
        data->status = 0;
        add_history(data->cmd);
        //ft_parcing(data);
        //ft_fill_tokens(data->cmd, data);
        // split_tokens(&p_tokens); //this function is for spliting tokens by space this time not by pipe
        // while (data->list)
        // {
        //     // printf("token --> %s\n", p_tokens->content);
        //     data->list = data->list->next;
        // }
    }
    return (data->status);
}
