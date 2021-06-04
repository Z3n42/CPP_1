/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:34:26 by camartin          #+#    #+#             */
/*   Updated: 2021/04/21 16:48:21 by camartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	int	ini;
	int	second;

	ini = '0';
	while (ini <= n)
	{
		second = ini + 1;
		while (second <='9')
		{
			write (1, &ini, 1);
			write (1, &second, 1);
			write (1, ", ", 2);
			second++;
		}
		ini++;
	}
}
