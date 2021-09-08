/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:52:33 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/05 14:30:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "./minilibx/mlx.h"
#include "./libft/libft.h"
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
/* void	ft_putchar(char c) */
/* { */
/* 	write(1, &c, 1); */
/* } */

/* int	deal_key() */
/* { */
/* 	ft_putchar('X'); */
/* 	return (0); */
/* } */

int main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	float	 	x;
	float		y;
	int			avance;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 500;
	y = 1;
	avance = 0;
	while(avance < 500)
	{
		while(x > 300)
		{
			/* my_mlx_pixel_put(&img, 300 + count, 450, 0x00FF0000); */
			my_mlx_pixel_put(&img, avance + x, 50 + y, 0x00FF0000);
			/* my_mlx_pixel_put(&img, 50 + x, 50 + y, 0x00FF0000); */
			/* my_mlx_pixel_put(&img, 100 + x, 50 + y, 0x00FF0000); */
			/* my_mlx_pixel_put(&img, 1000 , 100 + count, 0x00FF0000); */
			/* my_mlx_pixel_put(&img, 100 + times, 100 + count, 0x00FF0000); */
			x -= 0.5;
			y += 1;
		}
		x = 500;
		y = 1;
		avance += 50;
		ft_printf("%d\n", avance);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	/* mlx_key_hook(win_ptr, deal_key, (void *)0); */
	mlx_loop(mlx);
}
