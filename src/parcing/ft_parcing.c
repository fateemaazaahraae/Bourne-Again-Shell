/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:28:11 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/07/22 19:25:16 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/minishell.h"

int filtre_1(t_data *data)
{
    int     i;

    i = 0;
    data->d_quote = false;
    data->s_quote = false;
    while (data->cmd[i])
    {
        if ((data->cmd[i] == '|' && data->cmd[i + 1] == '\0') || data->cmd[0] == '|')
            return (print_error(data, 's')); 
        if (data->cmd[i] == '"' && !data->s_quote)
            data->d_quote = !data->d_quote;
        else if (data->cmd[i] == '\'' && !data->d_quote)
            data->s_quote = !data->s_quote;
        i++;
    }
    if (data->s_quote == true || data->d_quote == true)
        return (print_error(data, 's'));
    return (0);
}

int is_special(char c, int flag)
{
    int i;
    char *check;

    check = " <|>;&*(){}[]\t";
    if (flag == 1 && c == '"')
        return (1);
    else if (flag == 2 && c == '\'')
        return (1);
    else if (flag == 3 && (c == '\'' || c == '"'))
        return (1);
        
    i = -1;
    while (check[++i])
        if (check[i] == c)
            return (1);
    return (0);
}

void    solve_between_quote(t_data *data)
{
    int i;
    int flag;

    data->d_quote = false;
    data->s_quote = false;
    i = -1;
    while (data->cmd[++i])
    {
        if (data->cmd[i] == '"' && !data->s_quote)
        {
            data->d_quote = !data->d_quote;
            flag = 2;   
        }
        else if (data->cmd[i] == '\'' && !data->d_quote)
        {
            data->s_quote = !data->s_quote;
            flag = 1;   
        }
        if ((data->d_quote || data->s_quote) && is_special(data->cmd[i], flag))
            data->cmd[i] *= -1;
    }
}

void solve_here_doc(t_data *data, int *i, char **str)
{
    if (data->cmd[*i] == '<' || data->cmd[*i] == '>')
    {
        if ((*i) > 0 && data->cmd[(*i) - 1] != ' ')
            *str = ft_strjoin_char(*str, ' ');
        *str = ft_strjoin_char(*str, data->cmd[*i]);
        if (data->cmd[*i + 1] == data->cmd[*i])
        {
            (*i)++;
            *str = ft_strjoin_char(*str, data->cmd[*i]);
        }
        if (data->cmd[*i + 1] != ' ' && data->cmd[*i + 1] != '\0')
            *str = ft_strjoin_char(*str, ' ');
    }
    else
        *str = ft_strjoin_char(*str, data->cmd[*i]);
    (*i)++;
    // if (data->cmd[*i] != '\0')
    //     solve_here_doc(data, i, str, here_doc);
}

void    return_special_char(t_data *data)
{
    int i;
    int j;

    t_list *tmp;

    tmp = data->list;
    while (tmp) // ls -la |||| cat hello
    {
        i = -1;
        while (tmp->mini_tokens[++i]) // ls -la
        {
            j = -1;
            while(tmp->mini_tokens[i][++j]) // l s - l a
            {
                if (is_special(tmp->mini_tokens[i][j] * (-1), 3))
                    tmp->mini_tokens[i][j] *= -1;
            }
        }
        tmp = tmp->next;   
    }
}

char *new_cmd(t_data *data)
{
    int i;
    char *str;

    i = -1;
    str = NULL;
    while (data->cmd[++i])
    {
        if (data->cmd[i] == ' ' && data->cmd[i + 1] == ' ')
            continue;
        if ((data->cmd[i] == '>' || data->cmd[i] == '<'))
            solve_here_doc(data, &i, &str);
        if (data->cmd[i] == '\'' || data->cmd[i] == '"')
            continue;
        str = ft_strjoin_char(str, data->cmd[i]);  
    }
    str = ft_strjoin_char(str, '\0');
    free(data->cmd);
    return (str);
}

int ft_filtre(t_data *data)
{
    data->cmd = ft_strtrim(data->cmd, " \t");
    if (filtre_1(data))
        return (data->status);
    solve_between_quote(data);
    data->cmd = new_cmd(data);
    return (0);
}