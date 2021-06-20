#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char s1[] = "s mundohj";
	char s2[] = "hola mundo";
	unsigned int n;
	int result;

	n = 2; 
//	result = ft_strncmp(s1, s2, n);
	result = strncmp(s1, s2, n);
	printf("cadena s1: %s\n", s1);
	printf("cadena s2: %s\n", s2);
	printf("valor de result: %d\n", result);
}
