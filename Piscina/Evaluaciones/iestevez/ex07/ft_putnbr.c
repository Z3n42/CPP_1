/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:34:52 by iestevez          #+#    #+#             */
/*   Updated: 2021/04/23 12:21:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar (char c)
{
	write (1, &c, 1);
}
	void ft_putnbr (int nb)
{
	if (nb >= -2147483648 || nb <= 2147483647)
	{
		if (nb == -2147483648)
		{
			nb = 147483648;
			ft_putchar ('-');
			ft_putchar ('2');
		}	
		if (nb < 0)
		{
		ft_putchar ('-');
		nb = (nb * -1);
		}
		if (nb > 9)e
		{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
		}
		else
			{
				ft_putchar (nb + 48);
			}
	}
}


void	ft_putnbr(int nb);

int	main ()
{
	ft_putnbr (44444);
}

