/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:18:25 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/25 10:26:31 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void here_doc(t_list *list)
{
    int heredoc_fd[2];
    char *line;
    
    while (list->limiter)
    {
        if (pipe(heredoc_fd) == -1)
        {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
        while ((line = readline("> ")) != NULL)
        {
            if (!ft_strcmp(line, list->limiter->lim))
            {
                free(line);
                break;
            }
            write(heredoc_fd[1], line, ft_strlen(line));
            write(heredoc_fd[1], "\n", 1);
            free(line);
        }
        close(heredoc_fd[1]);
        close(heredoc_fd[0]);
        list->limiter = list->limiter->next;
    }
}

void handle_child_process(t_data *data, t_list *list, int fd_in, int pipe_fd[2])
{
    if (fd_in != 0)
    {
        dup2(fd_in, 0);
        close(fd_in);
    }
    if (data->list->next)
    {
        dup2(pipe_fd[1], 1);
        close(pipe_fd[1]);
    }
    redirection(list, pipe_fd);
    ft_execve(data);
    exit(EXIT_SUCCESS);
}
