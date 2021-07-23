/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 18:12:00 by iibanez-          #+#    #+#             */
/*   Updated: 2021/07/01 18:25:27 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;
	long	n2;

	n2 = (long) n;
	if (n2 < 0)
	{
		write(fd, "-", 1);
		n2 = n2 * -1;
	}
	if (n2 < 10)
	{
		num = n2 + '0';
		write(fd, &num, 1);
	}
	if (n2 >= 10)
	{
		num = (n2 % 10) + '0';
		ft_putnbr_fd(n2 / 10, fd);
		write (fd, &num, 1);
	}
}
