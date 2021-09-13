/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:28:22 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/07 18:34:45 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"
#include "libft/ft_printf/ft_printf.h"

//Init img valors
t_img	init_img(void)
{
	t_img	img;

	img.floor = "text/floor.xpm";
	img.pj = "text/pj.xpm";
	img.wall = "text/wall.xpm";
	img.collec = "text/collectible.xpm";
	img.exit = "text/exit.xpm";
	img.img_w = 50;
	img.img_h = 50;
	return (img);
}

t_map	init_map(void)
{
	t_map	map;

	map.mlx_ptr = mlx_init();
	map.map_h = 0;
	map.map_w = 0;
	map.moves = 0;
	return (map);
}

t_map	draw_map(t_map	map)
{
	draw_floor(map);
	draw_wall(map);
	draw_exit(map);
	map = draw_pj(map);
	map.collec = draw_collec(map);
	return (map);
}

//void	put_floor()
//x and y must be de tiles/w/h * map/x/y (get_next_line)
//event 2 == press keymask 1L << 0 == keypress
//https://harm-smits.github.io/42docs/libs/minilibx/events.html
int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map = init_map();
		map = map_info(map, argv[1]);
		check_map(map);
		map.win_ptr = mlx_new_window(map.mlx_ptr,
				map.map_w * 50, map.map_h * 50, "Free Cthulhu!");
		map = draw_map(map);
		mlx_hook(map.win_ptr, 2, 1L << 0, close_game, &map);
		mlx_hook(map.win_ptr, 17, 1L << 17, close_game_x, &map);
		mlx_key_hook(map.win_ptr, move, &map);
		mlx_loop(map.mlx_ptr);
	}
	if (argc < 2)
		ft_printf("ERROR: Add a map!");
	else
		ft_printf("ERROR: Add a map properly! And just ONE!");
}
