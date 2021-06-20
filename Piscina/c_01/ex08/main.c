/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:07:34 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/27 11:38:11 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int	size;
	int	tab[5];

	size = 5;
	tab[0] = 3;
	tab[1] = 2;
	tab[2] = 1;
	tab[3] = 5;
	tab[4] = 4;
	ft_sort_int_tab(tab, size);
	printf("%d", tab[0]);
	printf("%d", tab[1]);
	printf("%d", tab[2]);
	printf("%d", tab[3]);
	printf("%d", tab[4]);
}
