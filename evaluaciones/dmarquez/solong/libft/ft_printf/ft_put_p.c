/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:23:39 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:42:39 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t nbr)
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

void	ft_print_ptr(uintptr_t nbr)
{
	if (nbr >= 16)
	{
		ft_print_ptr(nbr / 16);
		ft_print_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int	ft_put_ptr(va_list	args)
{
	int					printed;
	unsigned long long	ptr;

	printed = 0;
	ptr = (unsigned long long)va_arg(args, void *);
	printed += write(1, "0x", 2);
	if (ptr == 0)
		printed += write(1, "0", 1);
	else
	{
		ft_print_ptr(ptr);
		printed += ft_ptr_len(ptr);
	}
	return (printed);
}
