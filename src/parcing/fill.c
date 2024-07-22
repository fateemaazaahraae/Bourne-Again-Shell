/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:49:00 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/22 19:02:52 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

/* void split_tokens(t_list **p_tokens)
{
    t_list *tmp;

    tmp = *p_tokens;
    while (tmp)
    {
        (tmp)->mini_tokens = ft_split((tmp)->content, ' ');
        tmp = (tmp)->next;
    }
}

//in this function i will fill the return of split into a linked list

 */
void    return_pipe(t_list **p_tokens)
{
    int i;
    t_list  *tmp;

    tmp = *p_tokens;
    while (tmp)
    {
        i = -1;
        while (tmp->content[++i])
            if ((tmp->content[i] * (-1)) == '|')
                tmp->content[i] *= (-1);       
        tmp = tmp->next;
    }
}
// int ft_fill_tokens(t_list **p_tokens, char *str) // "'hello'"
// {
//     int i;
//     int start;
//     int end;
//     int flag;
//     t_list *new;

//     i = -1;
//     end = 0;
//     while (str[++i])
//     {
//         start = end;
//         if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') // ls -la 
//             end = i;
//         else if (str[i] == '>' || '<')
//         {
//             end = i;
//         }
//         else if (str[i] == '\"' || str[i] == '\'')
//         {
//             start = i;
//             end = reach_end_of_quote(str, i);
//         }
//         start = i;
//         new = ft_lstnew(ft_substr(str, start, end));
//         ft_lstadd_back(p_tokens, new);
//    }
//    return (0);
// }


// int reach_end_of_quote(char *str, int index)
// {
//     int i;
//     char c;
    
//     i = index - 1;
//     if (str[index] == '\'')
//         c = '\''; //""'hello'""
//     else
//         c = '\"';
//     while (str[++i])
//     {
//         if (str[i] == c)
//             return (i);
//     }
//     return (-1);
// }

// void    fill_cmd_args(t_data *data)
// {
//     int i;
//     int j;
//     t_list *tmp;

//     tmp = data->list;
//     while (tmp)
//     {
//         i = 0;
//         while (tmp->mini_tokens[i] && tmp->mini_tokens[i][0] != '<' && tmp->mini_tokens[i][0] != '>')
//             i++;
//         tmp->cmd_args = malloc(sizeof(char *) * (i + 1));
//         j = 0;
//         while (tmp->mini_tokens[j] && tmp->mini_tokens[j][0] != '<' && tmp->mini_tokens[j][0] != '>')
//         {
//             tmp->cmd_args[j] = ft_strdup(tmp->mini_tokens[j]);
//             j++;
//         }
//         tmp->cmd_args[j] = NULL;
//         tmp = tmp->next;
//     }
// }

// void fill_cmd_args(t_data *data)
// {
//     int i;
//     int j;
//     int k;
//     int len;
//     char **new_cmd_args;
//     t_list *tmp;

//     tmp = data->list;
//     while (tmp)
//     {
//         i = 0;
//         while (tmp->mini_tokens[i] && tmp->mini_tokens[i][0] != '<' && tmp->mini_tokens[i][0] != '>')
//             i++;
//         tmp->cmd_args = malloc(sizeof(char *) * (i + 1));
//         j = -1;
//         while (++j < i)
//             tmp->cmd_args[j] = ft_strdup(tmp->mini_tokens[j]);
//         tmp->cmd_args[j] = NULL;
//         k = i;
//         len = 0;
//         while (tmp->mini_tokens[k])
//         {
//             if (tmp->mini_tokens[k][0] != '<' && tmp->mini_tokens[k][0] != '>')
//             {
//                 k++;
//                 len++;
//             }
//             else
//                 k += 2;
//         }
//         new_cmd_args = malloc(sizeof(char *) * (i + len + 1));
//         j = -1;
//         while (++j < i)
//             new_cmd_args[j] = tmp->cmd_args[j];
//         free(tmp->cmd_args);
//         tmp->cmd_args = new_cmd_args;
//         j = i;
//         while (tmp->mini_tokens[i])
//         {
//             if (tmp->mini_tokens[i][0] == '>')
//             {
//                 if (tmp->mini_tokens[i][1] == '>')
//                     handle_input_output(data, tmp->mini_tokens, &i);
//                 else
//                     handle_input_output(data, tmp->mini_tokens, &i);
//                 i += 2;
//             }
//             else if (tmp->mini_tokens[i][0] == '<')
//             {
//                 if (tmp->mini_tokens[i][1] == '<')
//                     handle_here_doc(data);
//                 else
//                     handle_input_output(data, tmp->mini_tokens, &i);
//                 i += 2;
//             }
//             else
//             {
//                 tmp->cmd_args[j] = ft_strdup(tmp->mini_tokens[i]);
//                 tmp->cmd_args[j + 1] = NULL;
//                 j++;
//                 i++;
//             }
//         }
//         tmp = tmp->next;
//     }
// }


void fill_mini_tokens(t_data *data)
{
    t_list *tmp;

    tmp = data->list;
    while (tmp)
    {
        tmp->mini_tokens = ft_split(tmp->content, ' ');
        tmp->out = NULL;
        tmp->in = NULL;
        tmp = tmp->next;
    }
}

void    ft_fill_tokens(t_data *data)
{
    char **str;
    t_list  *new;

    str = ft_split(data->cmd, '|');
    int i = -1;
    while (str[++i])
    {
        new = ft_lstnew(str[i]);
        ft_lstadd_back(&data->list, new);
        free(str[i]);
    }
    free(str);
    // return_pipe(data);
    fill_mini_tokens(data);
    return_special_char(data);
    fill_cmd_args(data);
    // handle_here_doc(data);
}
