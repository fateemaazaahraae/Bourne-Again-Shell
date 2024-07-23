#ifndef PARCING_H
# define PARCING_H
 
// # include "minishell.h"
# include "env.h"

typedef struct s_data
{
    t_list *list;
    t_env   *my_env;
    char    *cmd;
    char    *new_cmd;
    int status;
    bool d_quote;
    bool s_quote;
} t_data;


/* -------------------------------PARCING--------------------------------*/
void split_tokens(t_list **p_tokens);
void    return_pipe(t_list **p_tokens);
void    ft_fill_tokens(t_data *data);

int print_error(t_data *data, char c);

void    solve_pipe_problem(char *str);
int check_synthax_error(char *str);
int is_all_space(char *str);
void    check_pipe(char *str, char *check);
int ft_filtre(t_data *data);
int filtre_1(t_data *data);
void solve_rederction_problem(t_data *data, int *i, char *str);
char	*ft_strjoin_char(char const *s1, char c);
void    return_special_char(t_data *data);
void    fill_cmd_args(t_data *data);
void    handle_here_doc(t_list *list);
int last_here_doc(char **args, int *i);
void    handle_input_output(t_list *list, char **args, int *i);
void ft_lstadd_back_redir(t_redir **redir, t_redir *new);
t_redir	*ft_lstlast_redir(t_redir *redir);
t_redir	*ft_lstnew_redir(char *name, int flag);

#endif