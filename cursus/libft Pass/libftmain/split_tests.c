#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

void	ft_print_split(char **split);
void	ft_check(char *s, char c);

int	main(void)
{
	ft_check(".", '.');
	ft_check(".a", '.');
	ft_check(".a.", '.');
	ft_check(".a.b", '.');
	ft_check("a.b.", '.');
	ft_check("..hello......world...", '.');
	ft_check(".hello.world", '.');
	ft_check("..hello......world...", '.');
	printf("---------- NEW TESTS ----------\n");
	ft_check("", '\0');
	ft_check("", '.');
	ft_check("hello\0world", '\0');
	return (0);
}

void	ft_check(char *s, char c)
{
	char	**split_result;

	split_result = ft_split(s, c);
	ft_print_split(split_result);
}

void	ft_print_split(char **split)
{
	char	**cpy;

	cpy = split;
	if (!split)
	{
		printf("NULL split\n");
		printf("\n\n");
		return ;
	}
	if (!(*split))
	{
		printf("split addr: %p\n", split);
		printf("NULL *split\n");
		printf("\n\n");
		return ;
	}
	while (*split)
	{
		printf("%s\n", *split);
		free(*split);
		split++;
	}
	printf("\n\n");
	free(cpy);
}
