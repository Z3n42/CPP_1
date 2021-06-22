/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchmain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:37:34 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/28 12:01:00 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar_fd(char c, int fd);

int	main(void)
{
	char	c;
	int		fd;

	c = 'g';
	fd = 1;
	ft_putchar_fd(c, fd);
}
