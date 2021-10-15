/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:22:47 by ecorreia          #+#    #+#             */
/*   Updated: 2021/10/11 17:59:51 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	size;

	size = 0;
	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			size += ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	return (size);
}

int	tam(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = (n * -1);
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
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

int	ft_integer(va_list vars)
{
	int		num;

	num = va_arg(vars, int);
	return (ft_putnbr_fd(num, 1));
}
