/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:39:09 by tiima             #+#    #+#             */
/*   Updated: 2024/07/08 20:10:44 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

static t_env *ft_lstnew2(char *name, char *value)
{
    t_env *new = (t_env *)malloc(sizeof(t_env));

    if (!new)
        return NULL;
    new->key = ft_strdup(name);
    new->value = ft_strdup(value);
    new->next = NULL;
    return (new);
}

static t_env	*ft_lstlast2(t_env *lst)
{
    t_env *tmp;

	if (!lst)
		return (NULL);
    tmp = lst;
	while (lst->next != NULL)
		lst = lst->next;
    lst = tmp;
	return (lst);
}

static void ft_lstadd_back2(t_env **lst, t_env *new)
{
    t_env *temp;

    if (!lst || !new)
        return;
    if (!(*lst))
        *lst = new;
    else
    {
        temp = *lst;
        *lst = ft_lstlast2(*lst);
        (*lst)->next = new;
        *lst = temp;
    }
}

t_env   *get_env(char **env)
{
    t_env *head;
    t_env *new;
    char *str;
    int i;

    i = 0;
    head = NULL;
    while(env[i])
    {
        str = ft_strchr(env[i], '=');
        if (str)
        {
            *str = '\0';
            new = ft_lstnew2(env[i], str + 1);
            printf("%s=%s\n", new->key, new->value);
            *str = '=';
            ft_lstadd_back2(&head, new);
        }
        i++;
    }
    return (head);
}