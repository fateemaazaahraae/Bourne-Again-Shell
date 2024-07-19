/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_non_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:10:58 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/18 16:56:21 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

char *get_cmd_path(char *cmd, char **paths)
{
    int i;
    char *cmd_path;

    if (!cmd || !paths)
        return (NULL);
    i = -1;
    while (paths[++i])
    {
        cmd_path = ft_strjoin(paths[i], "/");
        cmd_path = ft_strjoin(cmd_path, cmd);
        if (!access(cmd_path, X_OK))
            return (cmd_path);
        free(cmd_path);
    }
    return (NULL);
}

char *find_path(t_env *my_env)
{
    t_env *env;

    env = my_env;
    while (env)
    {
        if (!ft_strcmp(env->key, "PATH"))
            return (ft_strdup(env->value));
        env = env->next;
    }
    return (NULL);
}

void    execute_non_builtins(t_data *data)
{
    char *all_path;
    char **paths;
    char *cmd_path;

    all_path = find_path(data->my_env);
    paths = ft_split(all_path, ':');
    cmd_path = get_cmd_path(data->list->mini_tokens[0], paths);
    if (!cmd_path)
    {
        printf("minishell: %s: command not found\n", data->list->mini_tokens[0]);
        exit (127);
    }
    if (execve(cmd_path, data->list->mini_tokens, env_to_2D(data->my_env)))
        perror("execve");
}

