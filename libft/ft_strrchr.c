/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:58:54 by fbazaz            #+#    #+#             */
/*   Updated: 2023/11/22 12:21:19 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;
	char	*str;

	str = (char *)s;
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (str[length] == (char)c)
			return (str + length);
		if (length == 0)
			break ;
		length--;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	char	*str;
	str = ft_strrchr("tiima", 'i');
	printf("%s", str);
	//printf("%s", strrchr("tiima", 'i'));
} */