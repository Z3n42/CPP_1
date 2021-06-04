/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 07:53:40 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/04 11:39:28 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		ft_putchar(2);
		nb = 147483648;
	}
	if (nb <0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb <10)
	{
		ft_putchar(nb);
	}
	else
	{
		ft_putnbr(nb /10);
		ft_putnbr(nb %10);
	}
}
