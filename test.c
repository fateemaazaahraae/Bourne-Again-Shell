/* #include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
char *ft_strdup(const char *s)
{
    char *str;
    int i;

    if (!s)
        return (NULL);
    str = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

int ft_strchr(char *str, char c)
{
    int i;

    i = -1;
    while (str[++i])
        if (str[i] == c)
            return (1);
    return (0);
}
char *strjoin(char *s1, char *s2)
{
    char *str;
    int i;
    int j;

    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    str= malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return (NULL);
    i = -1;
    while (s1[++i])
        str[i] = s1[i];
    j = 0;
    while (s2[j])
    {
        str[i + j] = s2[j];
        i++;
        j++;
    }
    str[j + i] = '\0';
    return (str);
}

char *ft_get_line(char *str)
{
    int i;
    char *ptr;
    
    if (!str || !str[0])
        return (NULL);
    i = 0;
    while (str[i] != '\0' && str[i])
        i++;
    ptr = malloc(i * sizeof(char) + 2);
    if (!ptr)
        return (free(str), NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        ptr[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        ptr[i] = '\n';
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char *ft_read_line(int fd, char *str)
{
    int n_byte;
    char *buffer;
    char *tmp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(str), NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (free(str), NULL);
    n_byte = BUFFER_SIZE;  // Initialized n_byte to BUFFER_SIZE
    while (n_byte > 0)
    {
        n_byte = read(fd, buffer, BUFFER_SIZE);
        if (n_byte < 0)
            return (free(str), free(buffer), NULL);
        buffer[n_byte] = '\0';
        tmp = str;
        str = strjoin(str, buffer);
        free(tmp);
        if (ft_strchr(str, '\n'))
            return (free(buffer), str);
    }
    return (NULL);
}

char *save_rest(char *str)
{
    int i;
    int j;
    char *save;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    save = malloc(ft_strlen(str) - i + 1);
    if (!save)
        return (free(str), NULL);
    i++;
    j = 0;
    while (str[i])
    {
        save[j] = str[i];
        j++;
        i++;
    }
    save[j] = '\0';
    return (free(str), save);
}

char *get_next_line(int fd)
{
    static char *str;
    char *line;

    str = ft_read_line(fd, str);
    line = ft_get_line(str);
    str = save_rest(str);
    return (line);
} */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

int ft_strlen(const char *str) {
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strdup(const char *s) {
    char *str;
    int i = 0;

    if (!s)
        return NULL;
    str = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!str)
        return NULL;
    while (s[i]) {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

int ft_strchr(char *str, char c) {
    int i = 0;
    while (str[i]) {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

char *strjoin(char *s1, char *s2) {
    char *str;
    int i = 0;
    int j = 0;

    if (!s1)
        return ft_strdup(s2);
    if (!s2)
        return ft_strdup(s1);
    str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!str)
        return NULL;
    while (s1[i]) {
        str[i] = s1[i];
        i++;
    }
    while (s2[j]) {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return str;
}

char *ft_get_line(char *str) {
    int i = 0;
    char *ptr;

    if (!str || !str[0])
        return NULL;
    while (str[i] != '\0' && str[i] != '\n')
        i++;
    ptr = malloc(i + 2);  // Include space for '\n' and '\0'
    if (!ptr)
        return (free(str), NULL);
    i = 0;
    
    while (str[i] && str[i] != '\n') {
        ptr[i] = str[i];
        i++;
    }
    if (str[i] == '\n') {
        ptr[i] = '\n';
        i++;
    }
    ptr[i] = '\0';
    return ptr;
}

char *ft_read_line(int fd, char *str) {
    int n_byte;
    char *buffer;
    char *tmp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (free(str), NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (free(str), NULL);
    n_byte = BUFFER_SIZE;
    while (n_byte > 0) {
        n_byte = read(fd, buffer, BUFFER_SIZE);
        if (n_byte < 0)
            return (free(str), free(buffer), NULL);
        buffer[n_byte] = '\0';
        tmp = str;
        str = strjoin(str, buffer);
        free(tmp);
        if (ft_strchr(str, '\n'))
            return (free(buffer), str);
    }
    free(buffer);
    return str;
}

char *save_rest(char *str) {
    int i = 0;
    int j = 0;
    char *save;

    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])  // If no newline found, free str and return NULL
        return (free(str), NULL);
    save = malloc(ft_strlen(str) - i + 1);
    if (!save)
        return (free(str), NULL);
    i++;
    while (str[i]) {
        save[j] = str[i];
        j++;
        i++;
    }
    save[j] = '\0';
    free(str);
    return save;
}

char *get_next_line(int fd) {
    static char *str = NULL;
    char *line;

    str = ft_read_line(fd, str);
    if (!str)
        return NULL;
    line = ft_get_line(str);
    str = save_rest(str);
    return line;
}

int main(void)
{
    int fd;
    char *line;
    // Open the file in read-only mode
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }
int i;

    // Read and print each line
       while (i < 5)
       {
        line = get_next_line(fd);
        if (line){
            printf("%s", line);
            free(line);
        }
        else 
        {
            printf("(null)");
            return (1);
        }
       }
    // Close the file
    close(fd);
    return (0);
}