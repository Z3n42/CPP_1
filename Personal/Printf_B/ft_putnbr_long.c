/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:54:18 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/23 15:09:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putnbr_long(long int n, int fd)
{
	unsigned int	numb;
	static int len;

	numb = (unsigned int) n;
	if (numb > 9)
	{
		len = 0;
		ft_putnbr_long(numb / 10, fd);
		ft_putnbr_long(numb % 10, fd);
	}
	else
	{
		len++;
		ft_putchar_fd(numb + '0', fd);
	}
	return (len);
}
