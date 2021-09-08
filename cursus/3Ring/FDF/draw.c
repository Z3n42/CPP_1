/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 19:07:36 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/07 20:20:43 by ingonzal         ###   ########.fr       */
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

void ft_brasenham(t_data *img, int x, int y, int x1, int y1)
{
	int	dx;
	int dy;
	int m;
	int p;

	dx = x1 - x;
	dy = y1 - y;		
	m = dy/dx;
	p = 2 * (dy - dx);
	my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
	while(x < x1)
	{
		if (p <= 0)
		{
			x++;
			p = p+(2*dy);
		}
		else
		{
			x++;
			y++;
			p = p+(2*dy)+(2*dx);
		}
		/* printf("X => %d, Y => %d\n", x, y); */
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
	}
}

void ft_draw(t_aux *aux)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	int	 		x;
	int		 	x1;
	int			y;
	int			y1;
	int			avance;
	int			vert;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 500;
	y = 250;
	x1 = x + 1000/aux->x;
	y1 = y;
	avance = 0;
	vert = 0;
	/* ft_brasenham(&img, 0, 0, 50, 50); */
	while(vert < aux->y)
	{
		while(avance < aux->x)
		{
			ft_brasenham(&img, x, y, x1, y1);
			x += 1000/aux->x;
			x1 += 1000/aux->x;
			avance++;
			/* printf("Avance %d\n", avance); */
		}
		x = 500;
		x1 = x + 1000/aux->x;
		avance = 0;
		y += 500/aux->y;
		y1 += 500/aux->y;
		vert++;
		/* printf("Vert %d\n", vert); */
		/* x = 500; */
		/* y = 1; */
		/* avance += 50; */
		/* ft_printf("%d\n", avance); */
	}
	x = 500;
	y = 250;
	x1 = x + 1000/aux->x;
	y1 = y;
	avance = 0;
	vert = 0;
	while(vert < aux->x)
	{
		while(avance < aux->y)
		{
			ft_brasenham(&img, x, y, x1, y1);
			y += 500/aux->y;
			y1 += 500/aux->y;
			avance++;
			/* printf("Avance %d\n", avance); */
		}
		y = 250;
		y1 = y + 500/aux->y;
		avance = 0;
		x += 1000/aux->x;
		x1 += 1000/aux->x;
		vert++;
		/* printf("Vert %d\n", vert); */
		/* x = 500; */
		/* y = 1; */
		/* avance += 50; */
		/* ft_printf("%d\n", avance); */
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	/* mlx_key_hook(win_ptr, deal_key, (void *)0); */
	mlx_loop(mlx);
}
