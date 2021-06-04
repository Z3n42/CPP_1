/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikgarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:06:07 by mikgarci          #+#    #+#             */
/*   Updated: 2021/05/06 20:09:39 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb <= 2147483647 || nb >= -2147483648)
	{
		if (nb == -2147483648)
		{
			ft_putnbr(nb / 10);
			ft_print('8');
		}
		else if (nb < 0)
		{
			write(1, "-", 1);
			ft_putnbr(-nb);
		}
		else
		{
			if (nb > 9)
			{
				ft_putnbr(nb / 10);
				ft_putnbr(nb % 10);
			}
			else
				ft_print(nb + '0');
		}
	}
}

void	ft_putnbr(int nb);

int	main(void)
{
	ft_putnbr(55555);
}
