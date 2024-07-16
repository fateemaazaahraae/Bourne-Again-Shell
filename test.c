#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void    remove_(char *str)
{
    char    c;
    int        i;

    i = 0;
    if (!strncmp(str, "\"", -1))
        memset((void *)str, 0, 2);
    while (str[i])
    {
        c = str[i];
        if (c == '"' || c == '\'')
        {
            memmove(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
            str[ft_strlen(str) - 1] = 0;
            while (str[i] && str[i] != c)
                i++;
            if (str[i] == c)
                memmove(&str[i], &str[i + 1], ft_strlen(&str[i + 1]));
            str[ft_strlen(str) - 1] = 0;
        }
        else
            i++;
    }
}

int main()
{
    char *str;

    str = "hel\"loali\"hi";
    remove_(str);
    printf("%s\n", str);
}