/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:03:14 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:36:10 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 16;
	}
	return (len);
}

int	ft_put_hex(va_list	args, const char format)
{
	unsigned int	nbr;

	nbr = va_arg(args, unsigned int);
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_print_hexa(nbr, format);
	return (ft_hex_len(nbr));
}

void	ft_print_hexa(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_print_hexa(nbr / 16, format);
		ft_print_hexa(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
}
