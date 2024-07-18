#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "env.h"

typedef struct s_data
{
    t_list  *list;
    t_env   *my_env;
    char    *cmd;
    char    *new_cmd;
    int     status;
    bool    d_quote;
    bool    s_quote;
} t_data;

/* ----------------------BUILTINS------------------------ */
/* --echo.c-- */
int nb_args(char **args);
int echo(char **args);

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

/* ----------------------EXECUTION------------------------ */
/* --execution.c-- */
int execute(t_data *data);
int is_builtin(char *command);

/* --exec_builtin.c-- */
void    execute_builtin(t_data *data);

/* --exec_non_builtin.c-- */
void    execute_non_builtin(t_data *data);
char *find_path(t_env *my_env);
char *get_cmd_path(char *cmd, char **paths);


#endif