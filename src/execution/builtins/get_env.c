/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:39:09 by tiima             #+#    #+#             */
/*   Updated: 2024/07/09 13:47:03 by fbazaz           ###   ########.fr       */
=======
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:39:09 by tiima             #+#    #+#             */
/*   Updated: 2024/07/09 14:13:02 by aakouhar         ###   ########.fr       */
>>>>>>> 5ef2f3d8bfd47488cbd158d68b9c6fb409dc3cda
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

static int	ft_lstsize2(t_env *lst)
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
        }
        i++;
    }
    return (head);
}