#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_env{
    char *key;
    char *value;
    struct s_env *next;
}   t_env;

t_env   *get_env(char **env);

#endif