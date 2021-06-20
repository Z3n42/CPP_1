/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:58:51 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/26 13:30:46 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b);

int	main (void)
{
	int	x;
	int	y;

	x = 10;
	y = 3;
	ft_ultimate_div_mod(&x, &y);
	printf("Division %d, Resto %d", x, y);
}	
