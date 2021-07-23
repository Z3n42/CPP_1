/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:55:56 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/23 19:52:51 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_puts(va_list ap, const char *format, int count, int len)
{
	if(format[count] == 'c')
		len += ft_putchar_fd(va_arg(ap, int), 1);
	if(format[count] == 's')
		len += ft_putstr_fd(va_arg(ap, char *), 1);
	if(format[count] == 'p')
	{
		write(1, "0x", 2);
		len += ft_putnbr_p(va_arg(ap, unsigned long), 1);
	}
	if(format[count] == 'd' || format[count] == 'i')
		len += ft_putnbr_fd(va_arg(ap, int), 1);
	if(format[count] == 'u')
		len += ft_putnbr_long(va_arg(ap, unsigned int), 1);
	if(format[count] == 'x')
		len += ft_putnbr_hex(va_arg(ap, unsigned int), 1);
	if(format[count] == 'X')
		len += ft_putnbr_hexmay(va_arg(ap, unsigned int), 1);
	if(format[count] == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int	count;
	int	len;

	va_start(ap, format);
	count = 0;
	len = 0;
	while(format[count])
	{
		if(format[count] == '%')
		{
			count++;
			len += ft_puts(ap, format, count, 0);
			count++;
		}
		else	
		{
			ft_putchar_fd(format[count], 1);
			count++;
			len++;
		}
	}
	va_end(ap);
	return(len);
}
