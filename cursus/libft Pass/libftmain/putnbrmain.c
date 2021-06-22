/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 13:56:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/06 18:59:01 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd);

int	main(void)
{
	int	n;
	int	fd;

	n = -2147483648;
	fd = 1;
	ft_putnbr_fd(n, fd);
}
