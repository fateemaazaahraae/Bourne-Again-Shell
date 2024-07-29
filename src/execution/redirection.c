/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:55:06 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/29 19:25:44 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

// void    ft_dup2(int fd1, int fd2)
// {
//     if (dup2(fd1, fd2) == -1)
//     {
//         perror("dup2");
//         close(fd1);
//         exit(EXIT_FAILURE);
//     }
//     close(fd1);
// }

void    close_pipe(int *pipe)
{
    close(pipe[0]);
    close(pipe[1]);
}

void red_in_out(t_list *list, int *pipe_fd, int fd_in)
{
    t_redir *out;

    out = NULL;
    (void)fd_in;
    out = ft_lstlast_redir(list->out);
    if (list->next)
    {
        if (out && out->fd > 1)
        {
            dup2(out->fd, 1);
            close(out->fd);
        }
        else
        {
            dup2(pipe_fd[1], 1);
            close_pipe(pipe_fd);
        }
    }
    else if (out)
    {
        dup2(out->fd, 1);
        close(out->fd);
    }
}

void restore_stdio(int saved_stdin, int saved_stdout)
{
    dup2(saved_stdin, STDIN_FILENO);
    close(saved_stdin);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);
}

void save_stdio(int *saved_stdin, int *saved_stdout)
{
    *saved_stdin = dup(STDIN_FILENO);
    *saved_stdout = dup(STDOUT_FILENO);
    if (*saved_stdin == -1 || *saved_stdout == -1)
    {
        perror("dup");
        exit(EXIT_FAILURE);
    }
}

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
        if (list->limiter->next)
        {
            close(heredoc_fd[0]);
            close(heredoc_fd[1]);
        }
        list->limiter = list->limiter->next;
    }
    close(heredoc_fd[1]);
    dup2(heredoc_fd[0], STDIN_FILENO);
    close(heredoc_fd[0]);
}
