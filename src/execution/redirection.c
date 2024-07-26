/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 09:55:06 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/26 17:22:26 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

void    ft_dup2(int fd1, int fd2)
{
    printf("%i\n%i\n", fd1, fd2);
    // int i = 
    // printf("hh %i\n", dup2(fd1, fd2));
    if (dup2(fd1, fd2) == -1)
    {
        perror("dup2");
        close(fd1);
        exit(EXIT_FAILURE);
    }
    close(fd1);
}

// void red_in_out(t_list *list, int *saved_stdin, int *saved_stdout)
// {
//     t_redir *in;
//     t_redir *out;

//     *saved_stdin = dup(STDIN_FILENO);
//     *saved_stdout = dup(STDOUT_FILENO);
//     in = ft_lstlast_redir(list->in);
//     out = ft_lstlast_redir(list->out);
//     if (in)
//     {
//         printf("hi\n");
//         ft_dup2(in->fd, STDIN_FILENO);
//     }
//     if (out)
//     {
//         printf("hi\n");
//         ft_dup2(out->fd, STDOUT_FILENO);
//     }
// }

void red_in_out(t_list *list, int *pipe_fd, int fd_in)
{
    t_redir *in;
    t_redir *out;

    in = ft_lstlast_redir(list->in);
    out = ft_lstlast_redir(list->out);
    if (in)
    // {
    //     printf("ana hna\n");
        ft_dup2(in->fd, STDIN_FILENO);
    // }
    else if (pipe_fd[0] && fd_in != STDIN_FILENO)
    {
        // printf("ana hna\n");
        ft_dup2(fd_in, STDIN_FILENO);
    }
    if (out)
    {
        // printf("ana hna\n");
        ft_dup2(out->fd, STDOUT_FILENO);
    }
    else if (pipe_fd && pipe_fd[1] != STDOUT_FILENO)
    {
        printf("ana hna %i\n", pipe_fd[1]);
        ft_dup2(pipe_fd[1], STDOUT_FILENO);
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
        close(heredoc_fd[1]);
        close(heredoc_fd[0]);
        list->limiter = list->limiter->next;
    }
}
