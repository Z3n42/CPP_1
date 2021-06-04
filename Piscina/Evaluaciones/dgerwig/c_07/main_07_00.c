//////////////////
// c07 ex00
/////////////////

#include <stdio.h>
#include <string.h>
#include "v1/ex00/ft_strdup.c"

int	main(void)
{
	printf("Texto:             %s\n", strdup("strdup   : El perro de San Roque."));
	printf("Direccion memoria: %p\n", strdup("strdup   : El perro de San Roque."));
	printf("Texto:             %s\n", ft_strdup("ft_strdup: El perro de San Roque."));
	printf("Dirección memoria: %p\n", ft_strdup("ft_strdup: El perro de San Roque."));
	return (0);
}
