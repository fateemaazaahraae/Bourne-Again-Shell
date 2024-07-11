#ifndef PARCING_H
# define PARCING_H

/* -------------------------------PARCING--------------------------------*/

/* --fill.c-- */
void    ft_fill_tokens(char *cmd);

/* --check.c-- */
void    solve_pipe_problem(char *str);
void    check_synthax_error(char *str);
void    check_pipe(char *str, char *check);

/* --errors.c-- */
void     print_error(char c);

#endif