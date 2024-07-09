#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_env{
    char *key;
    char *value;
    struct s_env *next;
}   t_env;

/* ----------------------BUILTINS------------------------ */
/* --echo.c-- */
int nb_args(char **args);
int echo(char **args);

/* --get_env.c && get_env_utils.c-- */
t_env   *get_env(char **env);
t_env *ft_lstnew2(char *name, char *value);
void ft_lstadd_back2(t_env **lst, t_env *new);

/* --cd.c-- */
void    cd(char **args, t_env *env);
void    update_old_pwd(t_env *env);
void    go_to_home(t_env *env);
void    update_pwd(t_env *env);

/* --pwd.c-- */
void    pwd(t_env *env);

/* --env.c-- */
void    env(t_env *env);

/* --unset.c-- */
void    unset_var(t_env **env, char *key);
void    unset(char **args, t_env *env);

/* --export.c-- */
void    export(char **args, t_env *env);


#endif