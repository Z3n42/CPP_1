/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:24:36 by ecorreia          #+#    #+#             */
/*   Updated: 2021/10/11 17:48:47 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_len(unsigned long nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

int	ft_print_pointer(unsigned long nbr)
{
	int	size;

	size = 0;
	if (nbr >= 16)
	{
		size += ft_print_pointer(nbr / 16);
		size += ft_print_pointer(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			size += ft_putchar_fd((nbr + '0'), 1);
		else
			size += ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
	return (size);
}

int	ft_pointer(va_list vars)
{
	unsigned long	num_args;
	int				size;

	size = 0;
	num_args = (unsigned long)va_arg(vars, void *);
	size += write(1, "0x", 2);
	if (num_args == 0)
		size += write(1, "0", 1);
	else
		size += ft_print_pointer(num_args);
	return (size);
}
