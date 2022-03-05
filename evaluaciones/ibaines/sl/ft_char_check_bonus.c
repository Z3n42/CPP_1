/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:01:15 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 13:01:34 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_check_charac_b(t_game *g, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->map[j] && j < g->mh)
	{
		while (g->map[j][i] && i < size - 1)
		{
			if (g->map[j][i] != 'C' && g->map[j][i] != 'E' \
					&& g->map[j][i] != 'P' && g->map[j][i] != '1' \
					&& g->map[j][i] != '0' && g->map[j][i] != 'X')
				return (1);
		i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
