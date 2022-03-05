/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_m.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:16:45 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 10:37:29 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	ft_close_map_mid_check(char **map, int mh, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] && j < mh)
	{
		while (map[j][i])
		{
			if ((map[j][0] != '1') || (map[j][size - 2] != '1'))
			{
				printf("Error\nEl mapa no está cerrado\n");
				return (1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_close_map_top_check(char **map, int size)
{
	int	i;

	i = 0;
	while (map[0][i] && i < size - 1)
	{
		if (map[0][i] != '1')
		{
			printf("Error\nEl mapa no está cerrado\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_close_map_bot_check(char **map, int mh, int size)
{
	int	i;

	i = 0;
	while (map[mh - 1][i] && i < size - 1)
	{
		if (map[mh - 1][i] != '1')
		{
			printf("Error\nEl mapa no está cerrado\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_close_map_check(char **map, int mh)
{
	int	size;

	size = (int)ft_strlen(map[0]);
	if (ft_close_map_top_check(map, size) == 1)
		return (1);
	if (ft_close_map_mid_check(map, mh, size) == 1)
		return (1);
	if (ft_close_map_bot_check(map, mh, size) == 1)
		return (1);
	else
		return (0);
}
