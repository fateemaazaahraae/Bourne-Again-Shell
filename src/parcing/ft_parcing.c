/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:28:11 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/07/19 17:16:39 by ali-akouhar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/minishell.h"

/* void    reach_second_quote(char *str, int i, char c)
{
    while (str[++i])
    {
        if (str[i] == c)
        {
            str[i] *= -1;
            break;
        }
    }
}

void    reach_first_quote(char *str, int i, char c)
{
    --i;
    while (i >= 0)
    {
        if (str[i] == c)
        {
            str[i] *= -1;
            break;   
        }
        i--;
    }
}

// void    remove_invalide_quote(t_data *data)
// {
//     int i;

//     data->d_quote = false;
//     data->s_quote = false;
//     i = -1;
//     while (data->cmd[++i])
//     {
        
//     }
//     printf("--> %s\n", data->cmd);
// }
void    remove_invalide_quote(t_data *data)
{
    int i;

    data->d_quote = false;
    data->s_quote = false;
    i = -1;
    while (data->cmd[++i])
    {
        if (data->cmd[i] == '"' && !data->s_quote)
            data->d_quote = !data->d_quote;
        else if (data->cmd[i] == '\'' && !data->d_quote)       
            data->s_quote = !data->s_quote;
        if (data->cmd[i] == '"')
        {
            if (data->cmd[i - 1] != ' ' && data->d_quote && i != 0)
            {                                                         // ec"h"o "ls"
                data->cmd[i] *= -1; // "hello"
                reach_second_quote(data->cmd, i, '"');
            }
            else if (data->cmd[i + 1] != ' ' && data->cmd[i + 1] != '\0' && !data->d_quote)
            {
                data->cmd[i] *= -1;
                reach_first_quote(data->cmd , i - 1, '"');
            }
        }
        else if (data->cmd[i] == '\'')
        {
            if (data->cmd[i - 1] != ' ' && data->s_quote)
            {
                data->cmd[i] *= -1; // "hello"
                reach_second_quote(data->cmd, i, '\'');
            }
            else if (data->cmd[i + 1] != ' ' && data->cmd[i + 1] != '\0' && !data->s_quote)
            {
                data->cmd[i] *= -1;
                reach_first_quote(data->cmd, i - 1, '\'');
            }
        }
    }
    printf("--> %s\n", data->cmd);
}

// char *new_str(t_data *data)
// {
//     char *new_cmd;
//     int i;

//     i = -1;
//     while (data->cmd[++i])
//     {
//         if (data->cmd[i] * -1 == '"' || data->cmd[i] * -1 == '\'' )
//             continue;
//         if (data->cmd[i] == ' ' && data->cmd[i + 1] == ' ')
//             continue;
//         ft_strjoin(new_cmd, (char *)data->cmd[i]);
//     }
// }

// int ft_parcing(t_data *data)
// {
//     data->cmd = ft_strtrim(data->cmd, " \t");
//     // solve_pipe_problem(data->cmd);
//     // if(check_synthax_error(data->cmd) || check_quote(data))
//     //     return (data->status);
//     remove_invalid_quote(data);
//     // data->cmd = new_str(data);
    
// } // l"s" */

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

int is_special(char c)
{
    int i;
    char *check;

    check = " <|>;&*(){}[]\t";
    i = -1;
    while (check[++i])
        if (check[i] == c)
            return (1);
    return (0);
}

void    solve_between_quote(t_data *data)
{
    int i;

    data->d_quote = false;
    data->s_quote = false;
    i = -1;
    while (data->cmd[++i])
    {
        if (data->cmd[i] == '"' && !data->s_quote)
            data->d_quote = !data->d_quote;
        else if (data->cmd[i] == '\'' && !data->d_quote)
            data->s_quote = !data->s_quote;
        if ((data->d_quote || data->s_quote) && is_special(data->cmd[i]))
            data->cmd[i] *= -1;
    }
}

void solve_redirection_problem(t_data *data, int *i, char **str, int *flag)
{
    if (data->cmd[(*i) - 1] != ' ')
        *str = ft_strjoin_char(*str, ' ');
    if (data->cmd[(*i) + 1] != ' ')
        *flag = 1;
}

void solve_here_doc(t_data *data, int *i, char **str, int *here_doc)
{
    if (data->cmd[(*i) - 1] != ' ')
    {
        *str = ft_strjoin_char(*str, ' ');
        (*i)++;
    }
    if (data->cmd[(*i) + 1] != ' ')
        *here_doc = 1;
    *str = ft_strjoin_char(*str, data->cmd[*i]);
}

char *new_cmd(t_data *data)
{
    int i;
    char *str;
    int flag;
    int here_doc;

    i = -1;
    str = NULL;
    while (data->cmd[++i])
    {
        flag = 0;
        here_doc = 0;
        if (data->cmd[i] == ' ' && data->cmd[i + 1] == ' ')
            continue;
        if ((data->cmd[i] == '>' || data->cmd[i] == '<') && data->cmd[i + 1] == data->cmd[i])
            solve_here_doc(data, &i, &str, &here_doc);
        else if (data->cmd[i] == '>' || data->cmd[i] == '<')
            solve_redirection_problem(data, &i, &str, &flag);
        str = ft_strjoin_char(str, data->cmd[i]);
        if (flag)
            str = ft_strjoin_char(str, ' ');
        if (here_doc)
            str = ft_strjoin_char(str, ' ');   
    }
    printf("^^ %s\n", str);
    return (str);
}
int ft_filtre(t_data *data)
{
    data->cmd = ft_strtrim(data->cmd, " \t");
    if (filtre_1(data))
        return (data->status);
    solve_between_quote(data);
    data->cmd = new_cmd(data);
    // printf("$$ %s\n", data->cmd);
    return (0);
}