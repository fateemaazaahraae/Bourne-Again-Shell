/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:38:31 by aakouhar          #+#    #+#             */
/*   Updated: 2024/07/09 18:54:43 by aakouhar         ###   ########.fr       */
=======
/*   By: ali-akouhar <ali-akouhar@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:19:39 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/07/08 19:21:18 by ali-akouhar      ###   ########.fr       */
>>>>>>> e59c56b9b3cabcb4f21d77261c7ddf88e76152c3
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

<<<<<<< HEAD
int print_error(char c)
{
    if (c == 's')
    {
        printf("synthax error\n");
        // exit (127);
    }
    return (0);
=======
void    print_error(char c)
{
    if (c == 's')
        printf("synthax error\n");
>>>>>>> e59c56b9b3cabcb4f21d77261c7ddf88e76152c3
}