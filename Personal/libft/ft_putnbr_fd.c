/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:55:39 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/23 14:42:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	numb;
	static int	len;
	
	numb = (unsigned int) n;
	if (numb > 9)
	{
		len = 0;
		ft_putnbr_fd (numb / 10, fd);
		ft_putnbr_fd (numb % 10, fd);
	}
	else
	{
		len++;
		ft_putchar_fd (numb + '0', fd);
	}
	return (len);
}
