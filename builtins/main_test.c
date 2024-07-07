# include "../includes/minishell.h"

int echo(char **args);

int main()
{
    char *str[] = {"echo", "-n","salam","cv","     labas","bikhir", NULL};

    echo(str);
}