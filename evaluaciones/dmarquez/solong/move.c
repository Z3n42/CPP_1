/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:14:42 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/07 18:51:11 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/ft_printf/ft_printf.h"

void	move_pj(t_map	*map)
{
	if (map->filled_map[map->y][map->x] == 'E')
	{
		if (map->collec == 0)
		{
			mlx_destroy_window(map->mlx_ptr, map->win_ptr);
			ft_printf("Moves = %d\n", ++map->moves);
			ft_printf("Yes! You've done it little cutie!");
			exit (1);
		}
	}
	if (map->filled_map[map->y][map->x] == 'C')
		--map->collec;
	if (map->filled_map[map->y][map->x] != '1' &&
		map->filled_map[map->y][map->x] != 'E')
	{
		ft_printf("Moves = %d\n", ++map->moves);
		map->filled_map[map->y][map->x] = 'P';
		map->filled_map[map->p_y][map->p_x] = '0';
		draw_map(*map);
	}
	else
	{
		map->x = map->p_x;
		map->y = map->p_y;
	}
}

int	move(int	keycode, t_map	*map)
{
	map->p_x = map->x;
	map->p_y = map->y;
	if (keycode == 13)
		--map->y;
	if (keycode == 1)
		++map->y;
	if (keycode == 0)
		--map->x;
	if (keycode == 2)
		++map->x;
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		move_pj(map);
	return (0);
}
