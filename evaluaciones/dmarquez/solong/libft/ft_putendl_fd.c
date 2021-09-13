/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:14:45 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:58:57 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	pos;

	pos = 0;
	while (s != NULL && s[pos] != '\0')
	{
		ft_putchar_fd(s[pos], fd);
		pos++;
	}
	write(fd, "\n", 1);
}
