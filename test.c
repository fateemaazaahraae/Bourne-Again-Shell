#include <stdio.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    int    i;

    i = 0;
    while (s1[i] && s2[i] && i < (n - 1))
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}
int main()
{
    // int n = 3;
    char s1[] = "ayoub";
    char s2[] = "ayok";
    printf ("%d", ft_strncmp(s1, s2, 2));
}