#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char src[20] = "cruel";
	char dest[20] = "hola mundo ";

	ft_strcat(dest, src);
//	strcat(dest, src);
	printf("VALUE src: %s\n", src);
	printf("VALUE dest: %s\n", dest);
}
