# include "../../../includes/minishell.h"

int echo(char **args);
void    cd(char **args, t_env *env);

int main(int ac, char **av, char **envp)
{
    char *str;
    t_env *my_env;
    (void)ac;
    (void)av;

    my_env = get_env(envp);
    //     while (my_env)
    // {
    //     printf("<< %s=%s\n", my_env->key, my_env->value);
    //     my_env = my_env->next;
    // }
    while (1)
    {
        str = readline("minishell$>  ");
        add_history(str);
        char **ho = ft_split(str, ' ');
        if (!strcmp(ho[0], "cd"))
            cd(ho, my_env);
        else if (!strcmp(ho[0], "pwd"))
            pwd(my_env);
        else if (!strcmp(ho[0], "env"))
            env(my_env);
        else if (!strcmp(ho[0], "unset"))
            unset(ho, my_env);
        else if (!strcmp(ho[0], "export"))
            export(ho, my_env);
        else if (!strcmp(ho[0], "echo"))
            echo(ho);
    }
}