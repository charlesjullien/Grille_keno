#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int	compare_it(int *tab, int *array)
{
	int	i;
	int	j;
	int	verif;

	i = 0;
	j = 0;
	verif = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			if (tab[i] == array[j])
			{
				verif++;
			}
			j++;
		}
		i++;
	}
	if (verif > 10)
		return (0);
	else
		return (1);
}

int check_prev_grids(int *tab)
{
    FILE* file = NULL;
    int c = 0;
    int        array[20];
    int        i = 0;
    int            digit = 0;
	int count = 0;
    file = fopen("/Users/Charles/Desktop/fun/keno/resultats.txt", "r");
    while (i < 20)
    {
        array[i] = 0;
        i++;
    }
    i = 0;
    
    if (file != NULL)
    {
        while (c != EOF)
        {
            i = 0;
            while (i < 20)
            {
                while (c >= '0' && c <= '9')
                {
                    digit = digit * 10 + c - 48;
                    c = fgetc(file);
                }
                if (digit > 0)
                {
                    array[i] = digit;
                    i++;
                }
                digit = 0;
                while (!(c >= '0' && c <= '9') && c != EOF)
                    c = fgetc(file);
            }
			if (compare_it(tab, array) == 0)
				return (0);
        }
        fclose(file);
    }
    return (1);
}
