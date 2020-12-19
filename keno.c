#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int check_prev_grids(int *tab);

void	ft_putnbr(int nb)
{
	char		c;
	long int	n;

	n = nb;
	if (n < 0)
	{
		n = n * (-1);
		write(1, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10) + 48;
	write(1, &c, 1);
}

void	tab_init(int *tabnum)
{
	int		i;

	i = 0;
	while (i < 70)
	{
		tabnum[i] = 0;
		i++;
	}
}

int		check_if_unique(int	*tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < 20)
	{
		j = i + 1;;
		while (j < 20)
		{
				if (tab[i] == tab[j])
					return (0);
				j++;
		}
		i++;
	}
	return (1);
}

void	get_numbers(int	*tabnum)
{
	int		minnum;
	int		maxnum;
	int		numarray[20];
	int		i;
	int		j;

	minnum = 1;
	maxnum = 70;
	i = 0;
	srand((int)time(NULL));
	while (i < 20)
	{
		numarray[i] = 0;
		i++;
	}
	while (check_if_unique(numarray) == 0)
	{
		i = 0;
		while (i < 20)
		{
			numarray[i] = (rand() % (maxnum - minnum + 1)) + minnum;
			i++;
		}
	}
	i = 0;
	while (i < 70)
	{
		j = 0;
		while (j < 20)
		{
			if (i == numarray[j] - 1)
				tabnum[i] = numarray[j];
			j++;
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_numbers(int *tabnum)
{
	int		i;
	int		line;

	i = 0;
	ft_putstr("*** Voici les numéros gagnants du prochain tirage de Keno ***\n");
	while (i < 70)
	{
		line = 0;
		ft_putstr("\n\t\t\t");
		while (line < 5)
		{
			if (tabnum[i] != 0 && tabnum[i] < 10)
			{
				ft_putstr("  ");
				ft_putnbr(tabnum[i]);
			}
			else if (tabnum[i] != 0 && tabnum[i] >= 10)
			{
				ft_putstr(" ");
				ft_putnbr(tabnum[i]);
			}
			else
				ft_putstr("  •");

			line++;
			i++;
		}
	}
	ft_putstr("\n\n*€€ €€€ €€€.€€*|Tous les gagnants ont joués|*€€ €€€ €€€.€€*");
}

int main ()
{
	int		tabnum[70];
	int		tab[20];
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab_init(tabnum);
	get_numbers(tabnum);
	while (i < 20)
	{
		while (tabnum[j] == 0)
			j++;
		tab[i] = tabnum[j];
		i++;
		j++;
	}
	if (check_prev_grids(tab) == 1)
		print_numbers(tabnum);
	else
	{
		printf("50 pour cent ou plus de numéros similaires sur les tirages des 2 ans passés... relance...\n");
		main();
	}
	return (0);
}
