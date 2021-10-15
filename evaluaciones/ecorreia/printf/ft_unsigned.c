/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:40:07 by ecorreia          #+#    #+#             */
/*   Updated: 2021/10/11 18:03:35 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putuns_fd(unsigned int n, int fd)
{
	int		siz;
	long	h;
	int		i;
	long	num;
	int		size;

	num = (long)n;
	siz = tam(num) - 1;
	h = 1;
	i = 0;
	size = 0;
	while (i++ < siz)
		h *= 10;
	if (num < 0)
	{
		size += ft_putchar_fd('-', fd);
		num *= -1;
	}
	while (siz-- >= 0)
	{
		size += ft_putchar_fd('0' + (num / h), fd);
		num = num - (num / h * h);
		h /= 10;
	}
	return (size);
}

int	ft_unsigned(va_list args)
{
	unsigned int		num_args;

	num_args = va_arg(args, unsigned int);
	return (ft_putuns_fd(num_args, 1));
}
