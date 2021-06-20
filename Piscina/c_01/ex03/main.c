/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:45:17 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/26 12:49:05 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main (void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;

	a = 10;
	b = 3;
	div = &a;
	mod = &b;
	ft_div_mod(a, b, div, mod);
	printf("Division  %d, Resto  %d", a, b);
}
