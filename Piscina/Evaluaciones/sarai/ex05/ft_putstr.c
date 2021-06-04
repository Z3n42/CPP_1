#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	char	har;
	char	n;

	n = '\n';
	while (true)
	{
		har = *str;
		if (har == '\0')
		{
			write(1, &n, 1);
			break ;
		}
		write(1, &har, 1);
		str++;
	}
}
