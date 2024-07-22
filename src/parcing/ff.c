/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:16:08 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/22 18:49:14 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int count_initial_args(char **mini_tokens)
{
    int i;

    i = 0;
    while (mini_tokens[i] && mini_tokens[i][0] != '<' && mini_tokens[i][0] != '>')
        i++;
    return (i);
}
 
char **allocate_and_copy_args(char **mini_tokens, int count)
{
    int j;
    char **cmd_args;

    cmd_args = malloc(sizeof(char *) * (count + 1));
    if (!cmd_args)
        return (printf("Error while allocating cmd_args\n"), NULL);
    j = -1;
    while (++j < count)
        cmd_args[j] = ft_strdup(mini_tokens[j]);
    cmd_args[j] = NULL;
    return (cmd_args);
}

int count_additional_args(char **mini_tokens, int start)
{
    int len;

    len = 0;
    while (mini_tokens[start])
    {
        if (mini_tokens[start][0] != '<' && mini_tokens[start][0] != '>')
        {
            len++;
            start++;
        }
        else
            start += 2;
    }
    return (len);
}

char **reallocate_cmd_args(char **old_cmd_args, int old_count, int additional_count)
{
    int j;
    char **new_cmd_args;

    new_cmd_args = malloc(sizeof(char *) * (old_count + additional_count + 1));
    if (!new_cmd_args)
        return (printf("Error while allocating new_cmd_args\n"), NULL);
    j = -1;
    while (++j < old_count)
        new_cmd_args[j] = old_cmd_args[j];
    new_cmd_args[j] = NULL;
    return (new_cmd_args);
}

void handle_args_and_redirections(t_list *tmp, int *i, int *j)
{
    while (tmp->mini_tokens[*i]) {
        if (tmp->mini_tokens[*i][0] == '>') {
            handle_input_output(tmp, tmp->mini_tokens, i);
            (*i) += 2;
        } else if (tmp->mini_tokens[*i][0] == '<') {
            if (tmp->mini_tokens[*i][1] == '<') {
                handle_here_doc(tmp);
            } else {
                handle_input_output(tmp, tmp->mini_tokens, i);
            }
            (*i) += 2;
        } else {
            tmp->cmd_args[*j] = ft_strdup(tmp->mini_tokens[*i]);
            tmp->cmd_args[(*j) + 1] = NULL;
            (*j)++;
            (*i)++;
        }
    }
}

void fill_cmd_args(t_data *data)
{
    t_list *tmp = data->list;

    while (tmp)
    {
        int initial_count = count_initial_args(tmp->mini_tokens);
        tmp->cmd_args = allocate_and_copy_args(tmp->mini_tokens, initial_count);
        if (!tmp->cmd_args)
        {
            tmp = tmp->next;
            continue;
        }
        int additional_count = count_additional_args(tmp->mini_tokens, initial_count);
        char **new_cmd_args = reallocate_cmd_args(tmp->cmd_args, initial_count, additional_count);

        if (!new_cmd_args)
        {
            tmp = tmp->next;
            continue;
        }
        free(tmp->cmd_args);
        tmp->cmd_args = new_cmd_args;
        int j = initial_count;
        handle_args_and_redirections(tmp, &(int){0}, &j);
        tmp = tmp->next;
    }
}
