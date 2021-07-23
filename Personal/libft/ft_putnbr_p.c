/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:03:02 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/23 14:39:01 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_p(uintptr_t n, int fd)
{
	if (n > 15)
	{	
		ft_putnbr_p(n / 16, fd);
		ft_putnbr_p(n % 16, fd);
	}
	else
	{
		if(n > 9)
			n += 39;
		ft_putchar_fd(n + '0', fd);
	}
	return (14);
}
