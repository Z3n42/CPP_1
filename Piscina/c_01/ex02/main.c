/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:50:49 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/26 12:50:52 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b);

int 	main(void)
{
	int	*a;
	int	*b;
	int	x;
	int	y;

	x = 4;
	y = 5;
	a = &x;
	b = &y;
	ft_swap(a, b);
	printf("Valor de X %d\n", x);
	printf("Valor de Y %d\n", y);
}
