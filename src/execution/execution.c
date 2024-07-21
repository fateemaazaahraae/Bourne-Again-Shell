/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:16:28 by fbazaz            #+#    #+#             */
/*   Updated: 2024/07/21 16:24:45 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/minishell.h"

// void execute(t_data *data)
// {
//     // if (is_builtins(data->list->mini_tokens[0]) && data->list->next == NULL)
//     //     execute_builtins(data);
//     // else
//     // {
//     //     if (data->list->next == NULL)
//     //         execute_non_builtins(data, "one");
//     //     else
            
//     // }
//     // t_list *lst;
//     int     index;

//     // lst = data->list;
//     while (data->list)
//     {
//         if (is_builtins(data->list->mini_tokens[0]))
//             execute_builtins(data);
//         else
//         {
//             // if (lst == data->list)
//             //     index = 0;
//             // else if (lst->next == NULL)
//             //     index = 3;
//             // else
//             //     index = 2;
//                 // for (int i = 0; lst->mini_tokens[i]; i++)
//         // printf("--> %s\n", lst->mini_tokens[i]);
//             execute_non_builtins(data, index);
//         }
//         data->list = data->list->next;
//     }
//     // if (ft_lstsize(data->list) == 1 && is_builtins(data->list->mini_tokens[0]))
//     // {
//     //     execute_builtins(data);
//     //     return ;
//     // }
//     // execute_multi_pipe(data);
// }

void    open_pipes(int *pipe_fd)
{
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
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

void execute(t_data *data)
{
    int pipe_fd[2];
    pid_t pid;
    int fd_in = 0;

    while (data->list)
    {
        if (data->list->next)
            open_pipes(pipe_fd);
        if (is_builtins(data->list->mini_tokens[0]))
            execute_builtins(data);
        else
        {
            pid = fork_process();
            if (pid == 0)
                handle_child_process(data, fd_in, pipe_fd);
        }
        if (data->list->next)
            close(pipe_fd[1]);
        fd_in = pipe_fd[0];
        data->list = data->list->next;
        wait(NULL);
        // if (data->list->next)
        //     open_pipes(pipe_fd);
        // pid = fork_process();
        // if (pid == 0)
        //     handle_child_process(data, fd_in, pipe_fd);
        // else
        // {
        //     if (data->list->next)
        //         close(pipe_fd[1]);
        //     fd_in = pipe_fd[0];
        //     data->list = data->list->next;
        //     wait(NULL);
        // }
    }
}

