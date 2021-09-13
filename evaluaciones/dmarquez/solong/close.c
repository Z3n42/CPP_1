/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:45:00 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/07 17:01:57 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int	close_game(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit (1);
	}
	return (0);
}

int	close_game_x(t_map *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit (1);
}
