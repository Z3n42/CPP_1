/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:30:11 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:31:26 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list	args, const char format)
{
	int	printed;

	printed = 0;
	if (format == 'c')
		printed += ft_put_char(args);
	else if (format == 's')
		printed += ft_put_string(args);
	else if (format == 'd' || format == 'i')
		printed += ft_put_nbr(args);
	else if (format == 'u')
		printed += ft_put_unsig(args);
	else if (format == 'x' || format == 'X')
		printed += ft_put_hex(args, format);
	else if (format == 'p')
		printed += ft_put_ptr(args);
	else if (format == '%')
		printed += write(1, "%%", 1);
	return (printed);
}
