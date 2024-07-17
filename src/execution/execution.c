/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:16:28 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/17 13:11:31 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int is_builtin(char *command)
{
    return (!ft_strcmp(command, "cd") || 
            !ft_strcmp(command, "echo") ||
            !ft_strcmp(command, "pwd") ||
            !ft_strcmp(command, "export") ||
            !ft_strcmp(command, "unset") ||
            !ft_strcmp(command, "env") ||
            !ft_strcmp(command, "exit"));
}

int execute(t_data *data)
{
    if (ft_lstsize2(data->my_env) == 1)
    {
        if (is_builtin(data->list->mini_tokens[0]))
            execute_builtin(data);
        else
            execute_non_builtin(data);
    }
}