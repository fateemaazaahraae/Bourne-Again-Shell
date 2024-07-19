# include "../../includes/minishell.h"

void    fill_to(t_list **p_tokens)
{
    t_list *tmp;
    int i;

    tmp = *p_tokens;
    while (tmp)
    {
        tmp->mini_tokens = ft_split(tmp->content, ' ');
        tmp = tmp->next;
    }
    tmp = *p_tokens;
    while (tmp)
    {
        for (i = 0; tmp->mini_tokens[i]; i++)
            printf("1- %s\n", tmp->mini_tokens[i]);
        tmp = tmp->next;
    }
}
void    ft_fill_tokens(char *cmd, t_list **p_tokens)
{
    char **str;
    t_list  *new;

    str = ft_split(cmd, '|');
    int i = -1;
    while (str[++i])
    {
        new = ft_lstnew(str[i]);
        ft_lstadd_back(p_tokens, new);
        free(str[i]);
    }
    free(str);
    fill_to(p_tokens);
}

void    execute_non_builtin(t_data *data);

int init_program(t_data **data, char **envp)
{
    *data = malloc(sizeof(t_data));
    if (!(*data))
        return (printf("Failed to allocate memory for data\n"));
    (*data)->list = malloc(sizeof(t_list));
    if (!(*data)->list)
        return (free(*data), printf("Failed to allocate memory for data->list\n"));
    (*data)->list = NULL;
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
        ft_fill_tokens(data->cmd, &data->list);
        execute(data);
        return(127);
        // ft_free_struct(data);
    }
}