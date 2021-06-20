#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char src[20] = "hola";
	char dest[20] = "shkdjksd";
	unsigned int nb;

	nb = 3;
	ft_strncat(dest, src, nb);
//	strncat(dest, src, nb);
	printf("cadena src %s\n", src);
	printf("cadena dest %s\n", dest);
	printf("nb %d", nb);
	return (0);
}
