#ifndef PARCING_H
# define PARCING_H
 
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

#endif