/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexmay.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:02:20 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/23 14:45:01 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_hexmay(unsigned int n, int fd)
{
	static int len;

	if (n > 15)
	{
		len = 0;
		ft_putnbr_hexmay(n / 16, fd);
		ft_putnbr_hexmay(n % 16, fd);
	}
	else
	{
		len++;
		if(n > 9)
			n += 7;
		ft_putchar_fd(n + '0', fd);
	}
	return (len);
}
