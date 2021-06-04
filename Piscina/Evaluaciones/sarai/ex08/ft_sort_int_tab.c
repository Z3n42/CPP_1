#include <stdbool.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		r;
	int		in;
	bool	s;

	r = 0;
	while (true)
	{
		s = false;
		in = 0;
		while (in < size)
		{
			if (tab[in] > tab[in + 1])
			{
				ft_swap(&tab[in], &tab[in + 1]);
				s = true;
			}
			in++;
		}
		if (!s)
		{
			break ;
		}
		r++;
	}
}

void	debug_dump_array(int numbers[], int size)
{
	int	in;

	printf("[ ");
	in = 0;
	while (in < size)
	{
		printf("%d", numbers[in]);
		if (in != size - 1)
		{
			printf(", ");
		}
		in++;
	}
	printf(" ]");
}
