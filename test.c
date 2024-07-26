# include "unistd.h"

int main (int ac, char **av)
{
	int i = 0;
	int rep;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if ((av[1][i] >= 'a' && av[1][i] <= 'z') || (av[1][i] >= 'A' && av[1][i] <= 'Z')) // if it's a alpha
			{
				if (av[1][i] >= 'a' && av[1][i] <= 'z')
					rep = av[1][i] - 'a';
				if (av[1][i] >= 'A' && av[1][i] <= 'Z')
					rep = av[1][i] - 'A';
				while (rep > 0)
				{
					write (1, &av[1][i], 1);
					rep--;
				}
			}
			write (1, &av[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}