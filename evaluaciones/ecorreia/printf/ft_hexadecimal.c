/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:22:17 by ecorreia          #+#    #+#             */
/*   Updated: 2021/10/11 18:09:51 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nbr, int mayus)
{
	int	size;

	size = 0;
	if (nbr >= 16)
	{
		size += ft_print_hexa(nbr / 16, mayus);
		size += ft_print_hexa(nbr % 16, mayus);
	}
	else
	{
		if (nbr <= 9)
			size += ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (mayus == 0)
				size += ft_putchar_fd(nbr - 10 + 'a', 1);
			else
				size += ft_putchar_fd(nbr - 10 + 'A', 1);
		}
	}
	return (size);
}

int	ft_hexadecimal(va_list args, int mayus)
{
	int	nbr;

	nbr = va_arg(args, unsigned int);
	return (ft_print_hexa(nbr, mayus));
}
