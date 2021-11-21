/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenito- <hbenito-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:46:03 by hbenito-          #+#    #+#             */
/*   Updated: 2021/11/19 11:24:03 by hbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

/*int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		count += ft_putchar(*s);
		s++;
	}
	return (count);
}

int	ft_putnum(int num)
{
	int	count;

	count = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		num *= -1;
		count = ft_putchar('-');
	}
	if (num > 9)
		count += ft_putnum(num / 10);
	count += ft_putchar((num % 10) + 48);
	return (count);
}

int	ft_putunnum(unsigned int un)
{
	int	count;

	count = 0;
	if (un > 9)
		count += ft_putunnum(un / 10);
	count += ft_putchar((un % 10) + 48);
	return (count);
}

int	ft_putexa(size_t exa, char c)
{
	int		count;
	char	*b;

	if (c == 'x' || c == 'p')
		b = "0123456789abcdef";
	if (c == 'X')
		b = "0123456789ABCDEF";
	count = 0;
	if (exa > 15)
		count += ft_putexa(exa / 16, c);
	count += write(1, &b[exa % 16], 1);
	return (count);
}
*/
int	ft_format(va_list arg, char src)
{
	int	count;

	count = 0;
	if (src == 'c')
		count = ft_putchar(va_arg(arg, int));
	if (src == 's')
		count = ft_putstr(va_arg(arg, char *));
	if (src == 'p')
		count = ft_putstr("0x") + ft_putexa(va_arg(arg, size_t), src);
	if (src == 'd' || src == 'i')
		count = ft_putnum(va_arg(arg, int));
	if (src == 'u')
		count = ft_putunnum(va_arg(arg, unsigned int));
	if (src == 'x' || src == 'X')
		count = ft_putexa(va_arg(arg, unsigned int), src);
	if (src == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *src, ...)
{
	int		len;
	va_list	arg;

	len = 0;
	va_start(arg, src);
	while (*src)
	{
		if (*src != '%')
			len += ft_putchar(*src);
		else
		{
			src++;
			len += ft_format(arg, *src);
		}
		src++;
	}
	va_end(arg);
	return (len);
}
