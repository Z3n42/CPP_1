/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iechevar <iechevar@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:10:10 by iechevar          #+#    #+#             */
/*   Updated: 2021/05/06 10:04:25 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar (char c)
{
	c = c + 48;
	write(1, &c, 1);
}

int	negative ( int num)
{
	if (num == -2147483648)
		num = num + 1;
	if (num < 0)
		num = num * -1;
	return (num);
}

void	ft_putnbr( int nb)
{
	int	inbr;
	int	num[20];
	int	i;

	i = 0;
	inbr = nb;
	inbr = negative (inbr);
	if (nb < 0)
		ft_putchar (-3);
	while (inbr >= 10)
	{
		num[i] = inbr % 10;
		inbr = inbr / 10;
		i++;
	}
	num[i] = inbr;
	while (i >= 0)
	{
		if (nb == -2147483648 && i == 0)
			ft_putchar (num[i] + 1);
		else
			ft_putchar (num[i]);
		i--;
	}
}

void	ft_putnbr(int nb);

int	main(void)
{
	ft_putnbr(55555);
}
