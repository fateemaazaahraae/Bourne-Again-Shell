/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 14:30:57 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/19 11:52:44 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	init_norm(int *i, long long *res, int *sign)
{
	*i = 0;
	*res = 0;
	*sign = 1;
}

long long	ft_atoi_long(const char *str)
{
	int			i;
	long long	result;
	int			sign;

	init_norm(&i, &result, &sign);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (LONG_MAX - (str[i] - '0')) / 10)
		{
			if (sign == -1 && result == (long long)(LONG_MAX / 10) && (str[i]
					- '0') == 8)
				return (LONG_MIN);
			ft_error((char *)str);
		}
		result = result * 10 + (str[i++] - '0');
	}
	return (result * sign);
}

int	ft_isnumeric(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	len_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	ft_exit(char **args)
{
	int	count;
	int	exit_code;

	printf("exit\n");
	if (!args[1])
		exit(g_data->exit_status);
	count = len_args(args);
	if (!ft_isnumeric(args[1]))
	{
		exit_func(NUMERIC_ARGS, args[1]);
		exit(2);
	}
	exit_code = ft_atoi_long(args[1]);
	if (count > 2)
	{
		exit_func(EXIT_TOO_ARG, NULL);
		g_data->exit_status = 1;
		return ;
	}
	g_data->exit_status = exit_code;
	exit(exit_code);
}
