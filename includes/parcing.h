#ifndef PARCING_H
# define PARCING_H



void    ft_fill_tokens(char *cmd, t_list **p_tokens);
void    solve_pipe_problem(char *str);
void check_synthax_error(char c);
int print_error(char c);
void split_tokens(t_list **p_tokens);
void    return_pipe(t_list **p_tokens);

#endif