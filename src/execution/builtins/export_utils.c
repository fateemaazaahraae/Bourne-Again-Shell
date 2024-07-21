/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:35:41 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/21 18:53:21 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/minishell.h"

static void	swap_node(t_env *node1, t_env *node2)
{
	char	*tmp_env;
	char	*tmp_val;

	tmp_env = node1->key;
	tmp_val = node1->value;
	node1->key = node2->key;
	node1->value = node2->value;
	node2->key = tmp_env;
	node2->value = tmp_val;
}

static void	free_env(t_env	*env)
{
	t_env	*env2;

	while (env)
	{
		free(env->value);
		free(env->key);
		env2 = env->next;
		free(env);
		env = env2;
	}
}

static void	print_env(t_env *env)
{
	t_env	*env2;

	env2 = env;
	while (env2)
	{
		if (!env2->value)
			printf("declare -x %s\n", env2->key);
		else
			printf("declare -x %s=\"%s\"\n", env2->key, env2->value);
		env2 = env2->next;
	}
	free_env(env);
}

static void	duplicate_env(t_env *head, t_env **tmp)
{
	t_env	*h;

	h = head;
	while (h)
	{
		ft_lstadd_back2(tmp, ft_lstnew2(h->key, h->value));
		h = h->next;
	}
}

void	print_sorted_env(t_env *head)
{
	int		swap;
	t_env	*cur;
	t_env	*tmp;

	if (!head || !head->next)
		return ;
	swap = 1;
	tmp = NULL;
	duplicate_env(head, &tmp);
	while (swap)
	{
		swap = 0;
		cur = tmp;
		while (cur->next)
		{
			if (ft_strcmp(cur->key, cur->next->key) > 0)
			{
				swap_node(cur, cur->next);
				swap = 1;
			}
			cur = cur->next;
		}
	}
	cur = tmp;
	print_env(cur);
}