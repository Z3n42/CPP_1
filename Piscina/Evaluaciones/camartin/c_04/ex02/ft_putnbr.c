/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 20:20:51 by camartin          #+#    #+#             */
/*   Updated: 2021/04/30 12:11:16 by camartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	number;

	if (nb < 0)
	{
		number = (unsigned int)(-1 * nb);
		ft_putchar ('-');
	}
	else
		number = (unsigned int)nb;
	if (number > 9)
	{
		ft_putnbr (number / 10);
		ft_putnbr (number % 10);
	}
	else
		ft_putchar (number + '0');
}
