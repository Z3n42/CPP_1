/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:55:39 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/25 17:04:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	numb;
	static int len;
	
	if (n < 0)
	{
		len = 1;
		numb = (unsigned int)(n * (-1));
		write(fd, "-", 1);
	}
	else
		numb = (unsigned int) n;
	if (numb > 9)
	{
		ft_putnbr_fd (numb / 10, fd);
		ft_putnbr_fd (numb % 10, fd);
	}
	else
	{
		len++;
		ft_putchar_fd (numb + '0', fd);
		/* printf("len = %d\n", len); */
	}
	return (len);
}
