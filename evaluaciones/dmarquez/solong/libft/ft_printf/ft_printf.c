/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:28:28 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:34:28 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	printed;
	int	pos;

	printed = 0;
	pos = -1;
	va_list(args);
	va_start(args, format);
	while (format[++pos])
	{
		if (format[pos] == '%')
		{
			printed += ft_format(args, format[pos + 1]);
			pos++;
		}
		else
			printed += write(1, &format[pos], 1);
	}
	va_end(args);
	return (printed);
}
