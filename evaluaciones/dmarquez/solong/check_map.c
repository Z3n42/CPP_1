/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:00:36 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/04 16:59:08 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_map	map)
{
	check_pj(map);
	check_exit_collec(map);
	check_char(map);
	check_wall(map);
}

void	check_pj(t_map map)
{
	t_img	img;
	int		players;

	players = 0;
	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			if (map.filled_map[img.y][img.x] == 'P')
				players++;
			img.x++;
		}
		img.y++;
	}
	if (players != 1)
		error_inv_free(map);
}

void	check_wall(t_map map)
{
	t_img	img;

	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			if (map.filled_map[0][img.x] != '1')
				error_inv_free(map);
			if (map.filled_map[img.y][0] != '1')
				error_inv_free(map);
			if (map.filled_map[map.map_h - 1][img.x] != '1')
				error_inv_free(map);
			if (map.filled_map[img.y][map.map_w - 1] != '1')
				error_inv_free(map);
			img.x++;
		}
		img.y++;
	}
}

void	check_char(t_map map)
{
	t_img	img;
	int		players;

	players = 0;
	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			if (map.filled_map[img.y][img.x] != 'P'
				&& map.filled_map[img.y][img.x] != 'E'
				&& map.filled_map[img.y][img.x] != 'C'
				&& map.filled_map[img.y][img.x] != '1'
				&& map.filled_map[img.y][img.x] != '0')
				error_inv_free(map);
			img.x++;
		}
		img.y++;
	}
}

void	check_exit_collec(t_map map)
{
	t_img	img;
	int		exit;
	int		collec;

	collec = 0;
	exit = 0;
	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			if (map.filled_map[img.y][img.x] == 'E')
				exit++;
			if (map.filled_map[img.y][img.x] == 'C')
				collec++;
			img.x++;
		}
		img.y++;
	}
	if (exit < 1)
		error_inv_free(map);
	if (collec < 1)
		error_inv_free(map);
}
