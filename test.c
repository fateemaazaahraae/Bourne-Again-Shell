#include <stdio.h>



unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (size == 0)
		return (j);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (j);
}
int main(void)
{
    char src[] = "Hello, World!";
    char dest[20];

    printf("src: %s /// dest: %s /// src_size: %u\n", src, dest,ft_strlcpy(dest, src, 10));
}