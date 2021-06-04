/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iirazaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:56:14 by iirazaba          #+#    #+#             */
/*   Updated: 2021/04/21 11:46:35 by iirazaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nbr_absoluto;

	if (nb < 0)
	{
		nbr_absoluto = (unsigned int)(-1 * nb);
		putchar('-');
	}
	else
		nbr_absoluto = (unsigned int)nb;
	if (nbr_absoluto >= 10)
	{
		ft_putnbr(nbr_absoluto / 10);
		ft_putnbr(nbr_absoluto % 10);
	}
	else
		putchar(nbr_absoluto + '0');
}

int	main(void)
{
	ft_putnbr(-5);
}
