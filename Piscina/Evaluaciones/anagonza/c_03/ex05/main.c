#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char dest[11] = "hola mundo";
	char src[1] = "!";
	unsigned int size = 1;

//	ft_strlcat(dest, src, size);
	strlcat(dest, src, size);

	printf("valor de dest %s\n", dest);
	printf("valor de src %s\n", src);
	printf("lo que me devuelve la funcion %lu%s\n", strlcat(dest, src, size), dest);
	return (0);
}
