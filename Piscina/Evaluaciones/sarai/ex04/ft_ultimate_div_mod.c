#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	fin;
	int	res;

	fin = *a / *b;
	res = *a % *b;
	*a = fin;
	*b = res;
}
