//////////////////
// c07 ex01
/////////////////

#include <stdio.h>
#include <string.h>
#include "v1/ex01/ft_range.c"

int main(void)
{
	
	int *range;

	range = ft_range(-3, 19);
	printf("Valor mínimo: -3 // Valor máximo: 19 (no se imprime el valor máximo). \n");
	if (range == NULL)
	{
		printf("NULL pointer.\n");
		return (0);
	}
	for (int i = 0; i < 22; i++)
	{
		printf("%d ", range[i]);
	}
	return (0);
}
