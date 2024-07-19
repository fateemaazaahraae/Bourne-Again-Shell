/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/19 16:15:53 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"

int main(int ac, char **av, char **env)
{
    t_data *data;
    (void)ac;
    (void)av;
    (void)env;
    // int i;
// ls -la>"he was fun"|cat "he was fun" -----> ls    -la  >|   he was fun  |   cat  he was fun
    data = malloc(sizeof(t_data));
    data->list = malloc(sizeof(t_list));
    if (!data)
        printf("failed in allocation\n");
    //data->my_env = get_env(env);
    data->list = NULL;
    while (1)
    {
        data->cmd = readline("\x1b[32mminishell $> \x1b[0m");
        add_history(data->cmd);
        if (ft_filtre(data))
            continue;
        // data->status = 0;
        // remove_invalide_quote(data);
        // ft_parcing(data);
        // split_tokens(&p_tokens); //this function is for spliting tokens by space this time not by pipe
        // while (data->list)
        // {
        //     // printf("token --> %s\n", p_tokens->content);
        //     data->list = data->list->next;
        ft_fill_tokens(data);
        //     printf("cmd -->%s\n", data->cmd);
        // while (data->list)
        // {
        //     printf("content -->%s\n", data->list->content);
        //     i = 0;
        //     printf("-------------------------\n");
        //     while (data->list->mini_tokens[i])
        //     {
        //         printf("mini ---> %s\n", data->list->mini_tokens[i]);
        //         i++;
        //     }
        //     data->list = data->list->next;
        // }
    //     // }
    }
    return (data->status);
}
