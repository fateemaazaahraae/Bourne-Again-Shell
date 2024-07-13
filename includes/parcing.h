#ifndef PARCING_H
# define PARCING_H

/* -------------------------------PARCING--------------------------------*/
void    solve_pipe_problem(char *str);
void check_synthax_error(char *str);
int is_all_space(char *str);
void    check_pipe(char *str, char *check);
void split_tokens(t_list **p_tokens);
void    ft_fill_tokens(char *cmd, t_list **p_tokens);
void    return_pipe(t_list **p_tokens);
void print_error(char c);

#endif