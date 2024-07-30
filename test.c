# include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar((i % 10) + '0');
}

int main (int ac, char **av)
{
	int i = 0;
	while (i <= 10)
	{
		if (i % 2 == 0)
			ft_putnbr(i * 2);
		else
			ft_putnbr(i);
		write(1, "\n",1);
		i++;
	}
}