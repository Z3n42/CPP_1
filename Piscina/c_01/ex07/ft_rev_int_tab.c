/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 18:09:55 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/26 20:15:03 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{	
	int	change;
	int	cont;
	int	pos;

	cont = 0;
	pos = size -1;
	while (cont < pos)
	{
		change = tab[cont];
		tab[cont] = tab[pos];
		tab[pos] = change;
		pos--;
		cont++;
	}
}
