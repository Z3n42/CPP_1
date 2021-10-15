/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:34:27 by ecorreia          #+#    #+#             */
/*   Updated: 2021/10/11 18:09:32 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_args(const char *str, va_list vars, int i)
{	
	int	size;

	size = 0;
	i++;
	if (str[i] == '%')
		return (write(1, "%", 1));
	else if (str[i] == 'c')
		return (ft_char(vars));
	else if (str[i] == 's')
		return (ft_string(vars));
	else if (str[i] == 'p')
		return (ft_pointer(vars));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_integer(vars));
	else if (str[i] == 'u')
		return (ft_unsigned(vars));
	else if (str[i] == 'x')
		return (ft_hexadecimal(vars, 0));
	else if (str[i] == 'X')
		return (ft_hexadecimal(vars, 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	size;

	va_list (vars);
	va_start(vars, str);
	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			size += ft_args(str, vars, i);
			i = i + 2;
		}
		else
		{
			size += write(1, &str[i++], 1);
		}
	}
	va_end(vars);
	return (size);
}
