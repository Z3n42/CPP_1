#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char	**argv)
{
	char	*line;
	int		fd;
	int		x;

	x = 0;
	line = NULL;
	fd = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		line = get_next_line(fd);
		printf("Line = %s\n", line);
		while (line != NULL)
		{
			free (line);
			line = get_next_line(fd);
			printf("Line = %s\n", line);
			x++;
		}
	}
	printf("Valor final de count = %d", x);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 11:28:22 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/03 20:19:04 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"
#include "libft/ft_printf/ft_printf.h"
#include <stdio.h>

//Init img valors
t_img	init_img(void)
{
	t_img	img;

	img.floor = "tile.xpm";
	img.img_w = 50;
	img.img_h = 50;
	return (img);
}

/* t_map	init_map(void)
{
	t_map	map;

	map.mlx_ptr = mlx_init();
	map.map_h = 0;
	map.map_w = 0;
	return (map);
} */

//Close window with ESC
//Keycode == the keyboard´s key you press
int	close_game(int keycode, t_map *map)
{
	if (keycode == 53)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	return (0);
}

void	put_floor(t_map	map)
{
	t_img	img;

	img = init_img();
	img.img_ptr = mlx_xpm_file_to_image(map.mlx_ptr, img.floor,
			&img.img_w, &img.img_h);
	img.img_addr = mlx_get_data_addr(img.img_ptr,
			&img.bpp, &img.linelen, &img.endian);
	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			mlx_put_image_to_window(map.mlx_ptr, map.win_ptr,
				img.img_ptr, img.x * 50, img.y * 50);
			img.x++;
		}
		img.y++;
	}
}

//Cheack the last line to check rectangular map
//Meaby check if the map is bigger than 1920 x 1080?
/* void	map_widht(char	*map_file, t_map	map)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = 0;
	fd = open(map_file, O_RDONLY);
	if (!fd || fd == -1)
		error_open_exit();
	line = get_next_line(fd);
	if (!line)
		error_empty_exit();
	map.map_w = ft_strlen(line) - 1;
	if (map.map_w * 50 > 1920)
		error_big_exit();
}

void	map_hight(char	*map_file, t_map	map)
{
	int		fd;
	char	*line;
	int		y;

	line = NULL;
	y = 0;
	fd = 0;
	fd = open(map_file, O_RDONLY);
	if (!fd || fd == -1)
		error_open_exit();
	line = get_next_line(fd);
	y++;
	if (!line)
		error_empty_exit();
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	map.map_h = y;
	if (map.map_h * 50 > 1080)
		error_big_exit();
} */

//void	put_floor()
//x and y must be de tiles/w/h * map/x/y (get_next_line)
//event 2 == press keymask 1L << 0 == keypress
//https://harm-smits.github.io/42docs/libs/minilibx/events.html
/* int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		map = init_map();
		map_widht(argv[1], map);
		map_hight(argv[1], map);
		map.win_ptr = mlx_new_window(map.mlx_ptr,
				map.map_w * 50, map.map_h * 50, "Free Cthulhu!");
		put_floor(map);
		mlx_hook(map.win_ptr, 2, 1L << 0, close_game, &map);
		mlx_loop(map.mlx_ptr);
	}
	ft_printf("ERROR: Add a map!");
} */

int	main(void)
{
	t_map	map;

	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr,
			900, 900, "Free Cthulhu!");
	printf("Hola");
	put_floor(map);
	mlx_hook(map.win_ptr, 2, 1L << 0, close_game, &map);
	mlx_loop(map.mlx_ptr);
}
