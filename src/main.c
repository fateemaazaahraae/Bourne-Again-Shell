/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/29 13:18:17 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
// # include "../includes/parcing.h"

int init_program(t_data **data, char **envp)
{
    *data = malloc(sizeof(t_data));
    if (!(*data))
        return (printf("Failed to allocate memory for data\n"));
    (*data)->list = malloc(sizeof(t_list));
    if (!(*data)->list)
        return (free(*data), printf("Failed to allocate memory for data->list\n"));
    (*data)->list = NULL;
    (*data)->my_env = get_env(envp);
    return (0);
}

void    ft_handler(int x)
{
    if (x == SIGINT)
    {
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 1);
        rl_redisplay();
    }
}
int main(int ac, char **av, char **env)
{
    t_data *data;
    (void)ac;
    (void)av;

    if (init_program(&data, env))
        return (1);
    while (1)
    {
        signal(SIGINT, &ft_handler);
        data->cmd = readline("\x1b[32mminishell $> \x1b[0m");
            // printf("ggggggggggg %s\n", data->cmd);
        if (!data->cmd)
        {
            printf("exittttttttttttt\n");
            exit(0);
        }
        add_history(data->cmd);
        if (ft_filtre(data))
        {
            free(data->cmd);
            continue;
        }
        execute(data);
    }
    return (data->status);
}
