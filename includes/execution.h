#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"
# include "parcing.h"
# include "env.h"

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


/* ----------------------ENV------------------------ */
/* --get_env.c-- */
int	ft_lstsize2(t_env *lst);
t_env   *get_env(char **env);

/* --execution.c-- */
void execute(t_data *data);
pid_t    fork_process();
void    open_pipes(int *pipe_fd);

/* --get_env_utils.c */
t_env	*ft_lstnew2(char *name, char *value);
t_env	*ft_lstlast2(t_env *lst);
void	ft_lstadd_back2(t_env **lst, t_env *new);
void	ft_lstdelone2(t_env *lst);

/* --env_to_2D.c-- */
char **env_to_2D(t_env *env);


/* ----------------------EXECUTION------------------------ */
/* --exec_builtin.c-- */
int is_builtins(char *command);
void    execute_builtins(t_data *data, t_list *list);

/* --exec_non_builtin.c-- */
char *find_path(t_env *my_env);
char *get_cmd_path(char *cmd, char **paths);
void    ft_execve(t_data *data);

/* --multi_pipe.c-- */
void handle_child_process(t_data *data);
void execute_cmd(t_data *data, t_list *list, int *fd_in);
void here_doc(t_list *list);

/* --execution_tools.c-- */
// void    redirection(t_list *list, int *pipe_fd);
void red_in_out(t_list *list, int *pipe_fd, int fd_in);
void save_stdio(int *saved_stdin, int *saved_stdout);
void restore_stdio(int saved_stdin, int saved_stdout);


/* --ft_free.c-- */
void    ft_free_struct(t_data **data);
void    free_2D(char **str);
void    ft_lstclear2(t_list **lst);

void    close_pipe(int *pipe);


#endif