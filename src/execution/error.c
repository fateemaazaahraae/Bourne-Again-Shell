/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:35:04 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/30 12:24:19 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void    exit_func(t_error err, char *cmd)
{
    if (err == PIPE_ERR)
        ft_putendl_fd("minishell: error in open pipe", STDERR_FILENO);
    if (err == FORK_ERR)
        ft_putendl_fd("minishell: error in fork", STDERR_FILENO);
    if (err == ACCESS)
    {
        ft_putstr_fd("minishell: ", STDERR_FILENO);
        ft_putstr_fd(cmd, STDERR_FILENO);
        ft_putendl_fd(": Permission denied", STDERR_FILENO);
    }
    if (err == CMD_NOT_FOUND)
    {
        ft_putstr_fd("minishell: ", STDERR_FILENO);
        ft_putstr_fd(cmd, STDERR_FILENO);
        ft_putendl_fd(": command not found", STDERR_FILENO);
    }
    if (err == EXECVE)
        ft_putendl_fd("minishell: error in execve", STDERR_FILENO);
}
