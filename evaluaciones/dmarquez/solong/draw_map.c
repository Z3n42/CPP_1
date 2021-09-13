/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:15:18 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/09 11:59:55 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/ft_printf/ft_printf.h"

void	draw_floor(t_map	map)
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

t_map	draw_pj(t_map	map)
{
	t_img	img;

	img = init_img();
	img.img_ptr = mlx_xpm_file_to_image(map.mlx_ptr, img.pj,
			&img.img_w, &img.img_h);
	img.img_addr = mlx_get_data_addr(img.img_ptr,
			&img.bpp, &img.linelen, &img.endian);
	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			if (map.filled_map[img.y][img.x] == 'P')
			{
				mlx_put_image_to_window(map.mlx_ptr, map.win_ptr,
					img.img_ptr, img.x * 50, img.y * 50);
				map.x = img.x;
				map.y = img.y;
			}
			img.x++;
		}
		img.y++;
	}
	return (map);
}

void	draw_wall(t_map	map)
{
	t_img	img;

	img = init_img();
	img.img_ptr = mlx_xpm_file_to_image(map.mlx_ptr, img.wall,
			&img.img_w, &img.img_h);
	img.img_addr = mlx_get_data_addr(img.img_ptr,
			&img.bpp, &img.linelen, &img.endian);
	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			if (map.filled_map[img.y][img.x] == '1')
				mlx_put_image_to_window(map.mlx_ptr, map.win_ptr,
					img.img_ptr, img.x * 50, img.y * 50);
			img.x++;
		}
		img.y++;
	}
}

int	draw_collec(t_map	map)
{
	t_img	img;

	map.collec = 0;
	img = init_img();
	img.img_ptr = mlx_xpm_file_to_image(map.mlx_ptr, img.collec,
			&img.img_w, &img.img_h);
	img.img_addr = mlx_get_data_addr(img.img_ptr,
			&img.bpp, &img.linelen, &img.endian);
	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			if (map.filled_map[img.y][img.x] == 'C')
			{
				mlx_put_image_to_window(map.mlx_ptr, map.win_ptr,
					img.img_ptr, img.x * 50, img.y * 50);
				map.collec++;
			}
			img.x++;
		}
		img.y++;
	}
	return (map.collec);
}

void	draw_exit(t_map	map)
{
	t_img	img;

	img = init_img();
	img.img_ptr = mlx_xpm_file_to_image(map.mlx_ptr, img.exit,
			&img.img_w, &img.img_h);
	img.img_addr = mlx_get_data_addr(img.img_ptr,
			&img.bpp, &img.linelen, &img.endian);
	img.y = 0;
	while (img.y < map.map_h)
	{
		img.x = 0;
		while (img.x < map.map_w)
		{
			if (map.filled_map[img.y][img.x] == 'E')
				mlx_put_image_to_window(map.mlx_ptr, map.win_ptr,
					img.img_ptr, img.x * 50, img.y * 50);
			img.x++;
		}
		img.y++;
	}
}
