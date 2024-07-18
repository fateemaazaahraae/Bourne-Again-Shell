/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:09:46 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/17 16:26:25 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../../../includes/minishell.h"

int	ft_lstsize2(t_env *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
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
            // printf("%s=%s\n", new->key, new->value);
            *str = '=';
            ft_lstadd_back2(&head, new);
            // printf("--------------\n");
        }
        i++;
    }
    return (head);
}