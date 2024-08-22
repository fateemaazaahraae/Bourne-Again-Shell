/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:15:55 by fbazaz            #+#    #+#             */
/*   Updated: 2024/08/22 11:21:56 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../libft/libft.h"
# include "env.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef enum s_error
{
	PIPE_ERR,
	FORK_ERR,
	ACCESS,
	CMD_NOT_FOUND,
	EXECVE,
	NUM_ARGS,
	CD_TOO_ARGS,
	HOME_NOT_SET,
	OLDPWD_NOT_SET,
	CHDIR,
	ENV_ERR,
	EXPORT_ERR,
	NO_SUCH_FILE,
	PERR_DENIED,
	AMBIGUOUS,
	DIR_ERR,
	EXIT_TOO_ARG,
	NUMERIC_ARGS,
	HER_DOC_ERR
}			t_error;

/* ----------------------BUILTINS------------------------ */
/* --echo.c-- */
int			nb_args(char **args);
int			is_n_flag(char *arg);
int			echo(t_list *list);

/* --cd.c-- */
char		*find_key_env2(char *key);
void		set_value_env(char *key, char *value);
char		*new_cwd_env(char *str);
void		handle_path(char *str);
void		cd(char **args);

/* --pwd.c-- */
char		*ft_strjoin2(char *s1, char *s2);
void		pwd(void);

/* --env.c-- */
void		print_env2(void);
void		env(char **args);

/* --unset.c-- */
void		unset_var(t_env **env, char *key);
void		unset(char **args);

/* --export.c-- */
int			ft_is_alphanum(char *str);
void		get_node(t_env *new, char *s);
t_env		*get_new(char *str);
void		export(char **args);

/* --export_utils.c-- */
t_env		*get_if_exist(t_env **env, t_env *new);
void		lst_addexport(t_env **env, t_env *new);

/* --exit.c-- */
void		ft_exit(char **args);
int			len_args(char **args);
int			ft_isnumeric(char *str);
long long	ft_atoi_long(const char *str);

/* --print_sorted_env.c-- */
void		duplicate_env(t_env *head, t_env **tmp);
void		print_env(t_env *env);
void		free_env(t_env *env);
void		swap_node(t_env *node1, t_env *node2);
void		print_sorted_env(t_env *head);

/* ----------------------EXECUTION------------------------ */
/* --exec_builtin.c-- */
int			is_builtins(char *command);
void		execute_builtins(t_list *list);

/* --exec_non_builtin.c-- */
int			check_existence(char *cmd);
char		*get_cmd_path(char *cmd, char **paths);
char		*find_path(t_env *my_env);
void		ft_execve(t_list *list);

/* --execution_tools.c-- */
int			ft_error(char *s1);
void		open_pipes(int *pipe_fd);
pid_t		fork_process(void);
void		close_pipe(t_list *list);
void		wait_child(t_list *list);

/* --ft_free.c-- */
void		fre(void *p);
void		free_2d(char **str);
void		ft_free_struct(t_list **list);
int			free_env_ctrl_d(t_env **env);

/* --redirection.c-- */
int			is_there_outfile(t_redir *files);
void		dup_out_pipe(t_list *list);
void		restore_stdio(int saved_stdin, int saved_stdout);
void		save_stdio(int *saved_stdin, int *saved_stdout);

/* --execution.c-- */
void		ft_after2(int num);
int			execute_cmd(t_list *list);
void		run_execution(t_list *list);
void		execution(t_list *list);

/* --check_permission.c-- */
int			check_dir(char *name);
int			check_in(t_redir *in);
int			check_out(t_redir *out);
int			open_files(t_list *list);

/* --error.c-- */
void		ft_error1(t_error err, char *cmd);
void		ft_error2(t_error err, char *cmd);
void		ft_error3(t_error err, char *cmd);
void		ft_error4(t_error err, char *cmd);
void		exit_func(t_error err, char *cmd);

#endif