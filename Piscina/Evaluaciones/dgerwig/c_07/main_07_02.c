///////////////////////
// c07 ex02    dgerwig
///////////////////////

#include <stdio.h>
#include <string.h>
#include "v1/ex02/ft_ultimate_range.c"

int main()
{
	int *range;
	int range_size;

	range_size = ft_ultimate_range(&range, 3, 12);
	printf("Tamaño de range es %d\n", range_size);
	if (!range)
	{
		printf("NULL Pointer.\n");
		return (0);
	}
	for (int i = 0; i < range_size; i++)
	{
		printf("%d ", range[i]);
	}
	return (0);
}
