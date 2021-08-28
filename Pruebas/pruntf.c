/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruntf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:21:53 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/26 13:41:59 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[count] != '\0')
	{
		write (1, &s[count], 1);
		count++;
	}
	return (count);
}

void	ft_putnbr(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
	{
		(*len)++;
		ft_putchar(n + '0');
	}
}

void	ft_putnbr_x(int n, int *len)
{
	if (n > 15)
	{
		ft_putnbr_x(n / 16, len);
		ft_putnbr_x(n % 16, len);
	}
	else
	{
		(*len)++;
		if (n > 9)
			n += 39;
		ft_putchar(n + '0');
	}
}

int ft_puts(va_list ap, const char *fmt, int count)
{
	int len;

	len = 0;
	if (fmt[count] == 'c')
		len += ft_putchar(va_arg(ap, int));
	if (fmt[count] == 's')
		len += ft_putstr(va_arg(ap, char *));
	if (fmt[count] == 'd')
		ft_putnbr(va_arg(ap, int), &len);
	if (fmt[count] == 'x')
		ft_putnbr_x(va_arg(ap, unsigned int), &len);
	return (len);
}

int	ft_pruntf(const char *fmt, ...)
{
	va_list		ap;
	int			count;
	int			len;

	len = 0;
	count = 0;
	va_start(ap, fmt);
	while (fmt[count])
	{
		if (fmt[count] == '%')
		{
			count++;
			len += ft_puts(ap, fmt, count);
			count++;
		}
		else
		{
			ft_putchar(fmt[count]);
			count++;
			len++;
		}
	}
	va_end(ap);
	return(len);
}

int	main(void)
{	
	char 			a;
	int 			b;
	char*	c = "deeq";

	a = 'a';
	b =	1050;
	ft_pruntf("mia: c%c, s%s, d%d, x%x\n", a, c, b, b);
	printf("ori: c%c, s%s, d%d, x%x", a, c, b, b);
}
