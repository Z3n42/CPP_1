/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:07:25 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/27 11:40:23 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	change;
	int	cont;
	int	pos;

	cont = 0;
	while (cont < size)
	{
		pos = cont + 1;
		while (pos < size)
		{
			if (tab[cont] > tab[pos])
			{
				change = tab[cont];
				tab[cont] = tab[pos];
				tab[pos] = change;
			}
			pos++;
		}
		cont++;
	}
}
