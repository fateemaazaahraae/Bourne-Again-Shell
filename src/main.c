/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:40:49 by tiima             #+#    #+#             */
/*   Updated: 2024/07/30 17:58:58 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minishell.h"
// # include "../includes/parcing.h"

t_global *global_data = NULL;

int init_program(t_list **list, char **av, int ac, char **envp)
{
    (void)av;
    (void)envp;
    (void)list;
    // *list = malloc(sizeof(t_list));
    // *list = NULL;
    global_data = malloc(sizeof(t_global));
    // global_data->my_env = get_env(envp);
    global_data->exit_status = 0;
    if (ac != 1)
    {
    //    exit_func(NUM_ARGS, av[1]);
       exit(EXIT_FAILURE); 
    }
    return (0);
}

void    ft_handler(int x)
{
    if (x == SIGINT)
    {
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 1);
        rl_redisplay();
    }
}
int main(int ac, char **av, char **env)
{
    t_list  *list;

    // list = NULL;
    init_program(&list, av, ac, env);
    while (1)
    {
        // signal(SIGINT, &ft_handler);
        global_data->cmd = readline("\x1b[32mminishell $> \x1b[0m");
        // if (!global_data->cmd)
        // {
        //     printf("exittttttttttttt\n");
        //     exit(0);
        // }
        add_history(global_data->cmd);
        // list->i = 5;
        printf("**********************\n");
        list = ft_filtre();
        if (!list)
        {
            free(global_data->cmd);
            continue;
        }
        printf("((((()))))\n");
        // printf("vvvvvvvv%d\n", list->i);
        // t_list *tmp;
        // tmp = list;
        printf("list : %i\n", ft_lstsize(list));
        while (list)
        {
        printf("hello\n");
            printf("content--> %s\n", list->content);
            for (int i = 0; list->mini_tokens[i]; i++)
                printf("mini_tokens --> %s\n", list->mini_tokens[i]);
            for (int j = 0; list->cmd_args[j]; j++)
                printf("cmd_args --> %s\n", list->cmd_args[j]);
            printf("outfile --> %i\n", list->outfile);
            printf("outfile --> %i\n", list->outfile);
            list = list->next;
        }
        
        // execution(list);
        // ft_free_struct(&list);
    }
    return (global_data->exit_status);
}
