/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:52:08 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/17 13:10:40 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void    execute_builtin(t_data *data)
{
    if (ft_strcmp(data->list->mini_tokens[0], "cd") == 0)
        return cd(data->list->mini_tokens, data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "echo") == 0)
        return echo(data->list->mini_tokens);
    else if (ft_strcmp(data->list->mini_tokens[0], "pwd") == 0)
        return pwd(data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "export") == 0)
        return export(data->list->mini_tokens, data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "unset") == 0)
        return unset(data->list->mini_tokens, data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "env") == 0)
        return env(data->my_env);
    else if (ft_strcmp(data->list->mini_tokens[0], "exit") == 0)
        exit(0);
}