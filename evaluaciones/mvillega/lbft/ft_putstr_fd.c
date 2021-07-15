#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*cpointer;

	cpointer = s;
	if (s)
	{
		while (*cpointer != '\0')
		{
			write(fd, cpointer, 1);
			cpointer++;
		}
	}
}
