/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:16:03 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/22 11:36:25 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCING_H
# define PARCING_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* -------------------------------PARCING--------------------------------*/

/* --redir_lst_utils.c-- */
void	ft_lstclear_redir(t_redir **lst);
t_redir	*ft_lstnew_redir(char *name, int flag);
t_redir	*ft_lstlast_redir(t_redir *redir);
int		ft_lstsize_redir(t_redir *redir);
void	ft_lstadd_back_redir(t_redir **redir, t_redir *new);

/* --parcing_utils.c-- */
char	*ft_strdup_char(char c);
char	*ft_strjoin_char(char *s1, char c);

/* --open_here_doc.c-- */
void	ft_expand(int *i, char **str, char *line);
char	*expand_in_here_doc(char *line);
void	sig_here_doc(int num);
void	ctrl_c(t_redir *node);
int		here_doc(t_redir *node);

/* --here_doc_utils.c-- */
char	*filename(char *file);
char	*generate_filename(char *arr);

/* --ft_parcing.c-- */
int		filtre_1(void);
int		is_special(char c, int flag);
void	solve_between_quote(void);
char	*new_cmd(void);
t_list	*ft_filtre(void);

/* --fill.c-- */
void	handle_special_char(char *str);
int		fill_mini_tokens(t_list *list);
t_list	*ft_fill_tokens(void);
void	return_from_files(t_list *list, int x, t_redir *files);
void	return_special_char(t_list *list);

/* --fill_cmd_args.c-- */
int		fill_cmd_args(t_list *list);
int		handle_args_and_redir(t_list *tmp);
int		count_args(char **mini_tokens);

/* --files.c-- */
int		handle_here_doc(t_list *tmp, int i);
void	handle_input_output(t_list *tmp, char **args, int i);
void	solve_here_doc(int *i, char **str);

/* --check_quote.c-- */
void	handle_quote(char *token, int *j, char **str);
void	ft_norm(t_list *list, int i, int *j, char **str);
void	remove_quotes(t_list *tmp);
char	*remove_quote_from_lim(char *name, int *lim_flag);

/* --expand.c-- */
void	join_single_quote(int *i, char **str, char *content);
int		expand(int *i, char **str, char *content);
void	handle_expand(t_list *list);

/* --expand_utils.c-- */
char	*ft_join(char *s1, char *s2);
int		here_doc_vs_expand(int i, char *content);
int		handle_here_doc_expand(int *i, char **str, char *content);
void	handle_ambigous(int start, int end, char **str, char *content);
int		handle_last_exit_status(char **str, char c);

/* --errors.c-- */
int		is_oper(char c);
int		check_synthax(void);
int		print_error(char c, char x);

#endif