#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "parcing.h"
# include "env.h"

// typedef struct s_data
// {
//     t_list *list;
//     t_env   *my_env;
//     char    *cmd;
//     char    *new_cmd;
//     int status;
//     bool d_quote;
//     bool s_quote;
// } t_data;

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
void    pwd();

/* --env.c-- */
void    env(t_env *env);

/* --unset.c-- */
void    unset_var(t_env **env, char *key);
void    unset(char **args, t_env *env);

/* --export.c-- */
void    export(char **args, t_env *env);
void	print_sorted_env(t_env *head);

/* ----------------------EXECUTION------------------------ */
/* --execution.c-- */
void execute(t_data *data);

/* --exec_builtin.c-- */
int is_builtins(char *command);
void    execute_builtins(t_data *data, t_list *list);

/* --exec_non_builtin.c-- */
void    execute_non_builtins(t_data *data, int index);
char *find_path(t_env *my_env);
char *get_cmd_path(char *cmd, char **paths);
void    dup_fd(t_data *data, int index);
void    ft_execve(t_data *data);
void handle_child_process(t_data *data, t_list *list, int fd_in, int pipe_fd[2]);
void    redirection(t_list *list, int *pipe_fd);
void    ft_free_struct(t_data **data);
void free_2D(char **str);
void here_doc(t_list *list);

void    ft_fill_tokens(t_data *data);

// must add to libft
void ft_lstclear2(t_list **lst);

#endif