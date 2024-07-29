/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:12:30 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/29 17:58:49 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void    open_pipes(int *pipe_fd)
{
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    // else
    // {
    //     pipe_fd[0] = -1;
    //     pipe_fd[1] = STDOUT_FILENO;
    // }
}

pid_t    fork_process()
{
    pid_t pid;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return (pid);
}
