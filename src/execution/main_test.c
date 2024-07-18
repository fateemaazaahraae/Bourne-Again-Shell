# include "../../includes/minishell.h"

void    execute_non_builtin(t_data *data);

int init_program(t_data **data, char **envp)
{
    *data = malloc(sizeof(t_data));
    if (!(*data))
        return (printf("Failed to allocate memory for data\n"));
    (*data)->list = malloc(sizeof(t_list));
    if (!(*data)->list)
        return (free((*data)), printf("Failed to allocate memory for data->list\n"));
    (*data)->my_env = get_env(envp);
    return (0);
}

int main(int ac, char **av, char **envp)
{
    t_data *data;
    (void)ac;
    (void)av;

    if (init_program(&data, envp))
        return (1);
    while (1)
    {
        data->cmd = readline("minishell$>  ");
        add_history(data->cmd);
        data->list->mini_tokens = malloc(sizeof(char *) * 2);
        data->list->mini_tokens[0] = ft_strdup("cd");
        data->list->mini_tokens[1] = ft_strdup("~");
        // data->list->mini_tokens[2] = ft_strdup("hello");
        data->list->mini_tokens[2] = NULL;
        execute(data);
        // execute_non_builtin(data);
        // printf("hello\n");
        // env_to_2D(data->my_env);
        free(data->list->mini_tokens[0]);
        free(data->list->mini_tokens[1]);
        // free(data->list->mini_tokens[2]);
    }
}