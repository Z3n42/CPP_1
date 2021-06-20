#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char s1[5] = "aola";
	char s2[5] = "hola";
	int result;

	result = ft_strcmp(s1, s2);	
//	result = strcmp(s1, s2);
	printf("da 0 si son iguales, negativo si s1<s2, positivo si s2>s1\n");
	printf("vuelta:  %d\n", result);
}
