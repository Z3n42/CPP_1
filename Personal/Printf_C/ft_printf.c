/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:55:56 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/26 15:20:10 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_puts(va_list ap, const char *format, int count, int len)
{
	uintptr_t arg;
	
	if(format[count] == 'c')
		len += ft_putchar_fd(va_arg(ap, int), 1);
	if(format[count] == 's')
		len += ft_putstr_fd(va_arg(ap, char *), 1);
	if(format[count] == 'p')
	{
		arg = va_arg(ap, uintptr_t);
		write(1, "0x", 2);
		ft_putnbr_p(arg, 1);
		len += ft_mik(arg, len);
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
    static	int	len;

	len = 0;
	va_start(ap, format);
	count = 0;
	while(format[count])
	{
		if(format[count] == '%')
		{
			count++;
			len += ft_puts(ap, format, count, 0);
			count++;
			/* printf("putslen = %d\n", len); */
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
