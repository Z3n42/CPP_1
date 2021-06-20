#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
/*	char str[23] = "hola mundo";
	char to_find[23] = "o"; */
	char str[23] = "hojkl";
	char to_find[23] = ".ho";

	printf("valor devuelta funcion construida: %s\n", ft_strstr(str, to_find));
	printf("valor devuelta funcion propia: %s\n", strstr(str, to_find));
}
