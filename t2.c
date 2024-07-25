#include <stdarg.h>
#include <unistd.h>

void ft_putnbr(long int nb, int *len, int base)
{
    char *s;

    s = "0123456789abcdef";
    if (nb < 0)
    {
        *len += write(1, "-", 1);
        nb *= -1;
    }
    if (nb >= base)
        ft_putnbr(nb / base, len, base);
    *len += write(1, &s[nb % base], 1);
}

void putstr(char *str, int *len)
{
    int i;

    if (!str)
        str = "(null)";
    i = -1;
    while (str[++i])
        *len += write (1, &str[i], 1);
}
int ft_printf(char *str, ...)
{
    int i;
    int len;
    va_list list;

    i = -1;
    len = 0;
    va_start(list, str);
    while (str[++i])
    {
        if (str[i] == '%')
        {
            i++;
            if (str[i] == 'd')
                ft_putnbr(va_arg(list, int), &len, 10);
            else if (str[i] == 'x')
                ft_putnbr(va_arg(list, unsigned int), &len, 16);
            else if (str[i] == 's')
                putstr(va_arg(list, char *), &len);
        }
        else
            len += write(1, &str[i], 1);
    }
    va_end(list);
    return (len);

}