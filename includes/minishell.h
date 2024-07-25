#ifndef MINISHELL
# define MINISHELL

# include <stdio.h>
#include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "execution.h"
// # include "parcing.h"
// #include <curses.h>
// #include <term.h>

// typedef struct s_env
// {
//     char *key;
//     char *value;
//     struct s_env *next;
// }   t_env;

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

#endif