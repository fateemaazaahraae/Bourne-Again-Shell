/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:17:20 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/22 19:13:04 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

int last_here_doc(char **args, int *i)
{
    int j;

    j = (*i) + 1;
    while (args[j])
    {
        if (!ft_strcmp(args[(*i)], args[j]))
            return (1);
        j++;
    }
    return (0);
}

void    handle_here_doc(t_list *tmp)
{
    int     i;

    i = -1;
    while (tmp->mini_tokens[++i])
    {
        if (!ft_strcmp(tmp->mini_tokens[i], "<<") && !last_here_doc(tmp->mini_tokens, &i))
        {
            tmp->here_doc = 1;
            tmp->limiter = ft_strdup(tmp->mini_tokens[i + 1]);
        }
        else if (((tmp->mini_tokens[i][0] == '>' || tmp->mini_tokens[i][0] == '<') && !tmp->mini_tokens[i][1]) || !ft_strcmp(tmp->mini_tokens[i], ">>"))
            handle_input_output(tmp, tmp->mini_tokens, &i);
    }
}

void    handle_input_output(t_list *list, char **args, int *i)
{
    t_redir *new_redir;

    if ((args[(*i)][0] == '>' && !args[(*i)][1]) || !ft_strcmp(args[(*i)], ">>"))
    {
        if ((args[(*i)][0] == '>' && !args[(*i)][1]))
            new_redir = ft_lstnew_redir(args[(*i) + 1], 1); // OUTPUT >
        else
            new_redir = ft_lstnew_redir(args[(*i) + 1], 2); // APPEND >>
        ft_lstadd_back_redir(&list->out, new_redir);
    }
    else if (args[(*i)][0] == '<' && !args[(*i)][1])
    {
        new_redir = ft_lstnew_redir(args[(*i) + 1], 3); // INPUT <
        ft_lstadd_back_redir(&list->in, new_redir);
    }
}
