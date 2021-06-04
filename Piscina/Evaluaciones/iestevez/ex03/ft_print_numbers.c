/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:33:59 by iestevez          #+#    #+#             */
/*   Updated: 2021/04/22 11:34:04 by iestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
void	ft_print_numbers (void)
{
	char	primero;

	primero = '0';
	while (primero <='9')
	{
		write (1, &primero, 1);
		primero++;
	}
	write (1, "\n", 1);
}
