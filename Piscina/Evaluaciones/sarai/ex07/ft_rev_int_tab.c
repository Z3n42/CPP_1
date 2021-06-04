#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	in;
	int	tm;

	in = 0;
	while (in < size / 2)
	{
		tm = tab[in];
		tab[in] = tab[size - 1 - in];
		tab[size - 1 - in] = tm;
		in++;
	}
}
