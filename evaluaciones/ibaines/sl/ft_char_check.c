/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:56:41 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 12:57:34 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	ft_check_charac(t_game *g, int size)
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
					&& g->map[j][i] != '0')
				return (1);
		i++;
		}
		i = 0;
		j++;
	}
	return (0);
}
