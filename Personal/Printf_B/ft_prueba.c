/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prueba.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 14:35:59 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/24 15:25:57 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_prueba(int n, int fd)
{
	unsigned int	numb;
	static char		*str;

	str[0] = '\0';
	if (n < 0)
	{
		numb = (unsigned int)(n * (-1));
		write(fd, "-", 1);
	}
	else
		numb = (unsigned int) n;
	if (numb > 9)
	{
		ft_prueba(numb / 10, fd);
		ft_prueba(numb % 10, fd);
	}
	else
	{
		numb = numb + '0';
		str = ft_strjoin(str, numb);
		ft_putstr_fd(str, 1);
	}
	return (ft_strlen(str));
}
