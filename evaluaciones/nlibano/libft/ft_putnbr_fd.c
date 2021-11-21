/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlibano- <nlibano-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:01:52 by nlibano-          #+#    #+#             */
/*   Updated: 2021/11/19 18:26:27 by nlibano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	long int	i;

	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	else if (nb == 0)
		ft_putchar_fd('0', fd);
	i = 1;
	while (nb / i != 0)
		i *= 10;
	while (i != 1)
	{
		i /= 10;
		ft_putchar_fd((nb % (10 * i) - nb % i) / i + '0', fd);
	}
}
