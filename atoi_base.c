#include <stdio.h>

int ft_strlen(char *str)
{
    int length;

    length = 0;
    while (str[length])
        length++;
    return (length);
}

int ft_is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

int ft_is_valid_base(char *base)
{
    int i;
    int j;
    int len;

    i = 0;
    len = ft_strlen(base);
    if (len <= 1)
        return (0);
    while (i < len)
    {
        if (base[i] == '+' || base[i] == '-' || ft_is_whitespace(base[i]))
            return (0);
        j = i + 1;
        while (j < len)
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_get_index(char c, char *base)
{
    int i;

    i = 0;
    while (base[i])
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return -1;
}

int ft_atoi_base(char *str, char *base)
{
    int i = 0;
    int sign = 1;
    int result = 0;
    int base_len;

    if (ft_is_valid_base(base) == 0)
        return (0);
    base_len = ft_strlen(base);
    while (ft_is_whitespace(str[i]))  // Skip whitespaces in str
        i++;
    if (str[i] == '-' || str[i] == '+')  // Handle optional sign '-'
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])   // Convert the number
    {
        int index = ft_get_index(str[i], base);
        if (index == -1)
            break;
        result = (result * base_len) + index;
        i++;
    }
    return (result * sign);
}

int main()
{
    char *test1 = "42";
    char *base1 = "0123456789";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test1, base1, ft_atoi_base(test1, base1)); // Expected: 42

    char *test2 = "101010";
    char *base2 = "01";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test2, base2, ft_atoi_base(test2, base2)); // Expected: 42

    char *test3 = "2A";
    char *base3 = "0123456789ABCDEF";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test3, base3, ft_atoi_base(test3, base3)); // Expected: 42

    char *test4 = "-2A";
    char *base4 = "0123456789ABCDEF";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test4, base4, ft_atoi_base(test4, base4)); // Expected: -42

    char *test5 = "   +2A";
    char *base5 = "0123456789ABCDEF";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test5, base5, ft_atoi_base(test5, base5)); // Expected: 42

    char *test6 = "ZZ";
    char *base6 = "0123456789ABCDEF";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test6, base6, ft_atoi_base(test6, base6)); // Expected: 0 (invalid character in input string)

    char *test7 = "42";
    char *base7 = "01234+56789";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test7, base7, ft_atoi_base(test7, base7)); // Expected: 0 (invalid base)

    char *test8 = "42";
    char *base8 = "0123456789 ";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test8, base8, ft_atoi_base(test8, base8)); // Expected: 0 (invalid base)

    char *test9 = "42";
    char *base9 = "01234 56789";
    printf("ft_atoi_base(\"%s\", \"%s\") = %d\n", test9, base9, ft_atoi_base(test9, base9)); // Expected: 0 (invalid base)
}
