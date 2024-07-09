#ifndef MINISHELL
# define MINISHELL

# include <stdio.h>
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
#include <readline/readline.h>
#include <readline/history.h>
# include "../libft/libft.h"
# include "execution.h"
# include "parcing.h"
// #include <curses.h>
// #include <term.h>

typedef struct s_minishell
{
    t_env *env;
} t_minishell;


#endif