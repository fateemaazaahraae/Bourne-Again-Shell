/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/24 08:46:02 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
// # include "../includes/parcing.h"


int main(int ac, char **av, char **env)
{
    t_data *data;
    (void)ac;
    (void)av;
    (void)env;
    data = malloc(sizeof(t_data));
    data->list = malloc(sizeof(t_list));
    if (!data)
        printf("failed in allocation\n");
    // data->my_env = get_env(env);
    data->list = NULL;
    while (1)
    {
        data->cmd = readline("\x1b[32mminishell $> \x1b[0m");
        add_history(data->cmd);
        if (ft_filtre(data))
            continue;
        ft_fill_tokens(data);
        while (data->list)
        {
            for (int i = 0; data->list->cmd_args[i]; i++)
                printf("& %s\n", data->list->cmd_args[i]);
            // if (data->list->here_doc && data->list->limiter)
            printf("-- %i -- %s -- \n", data->list->here_doc, data->list->limiter);
            if (data->list->in)
            {
                t_redir *in = ft_lstlast_redir(data->list->in);
                printf("in : *fd  %i\n", in->fd);
                printf("in : *name  %s\n", in->name);
                printf("in : *type  %i\n", in->type);
            }
            else
                printf("there is no input file\n");
            if (data->list->out)
            {
                t_redir *out = ft_lstlast_redir(data->list->out);
                printf("out : *fd  %i\n", out->fd);
                printf("out : *name  %s\n", out->name);
                printf("out : *type  %i\n", out->type);
            }
            else
                printf("there is no output file\n");
            printf("--------------------\n\n");
            data->list =  data->list->next;
        }
        // int i;
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
    }
    return (data->status);
}
