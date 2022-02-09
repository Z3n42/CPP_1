/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 20:34:19 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 14:19:51 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "./minilibx-linux/mlx.h"

void	my_mlx_pixel_put(t_window *win, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * win->imgdata->line_length + \
				x * (win->imgdata->bits_per_pixel / 8);
	dst = win->imgdata->addr + offset;
	*(unsigned int *)dst = color;
}

static void	set_bresen_values(t_bresen *bres, t_pair *pair, int *y, int *x)
{
	bres->dx = abs(pair->x_end - pair->x_start);
	if (pair->x_start < pair->x_end)
		bres->sx = 1;
	else
		bres->sx = -1;
	bres->dy = -abs(pair->y_end - pair->y_start);
	if (pair->y_start < pair->y_end)
		bres->sy = 1;
	else
		bres->sy = -1;
	bres->err = bres->dx + bres->dy;
	*y = pair->y_start;
	*x = pair->x_start;
}

static int	check_image_limits(t_window *win, int x, int y)
{
	if (x >= 0 && x < win->x_max)
	{
		if (y >= 0 && y < win->y_max)
			return (1);
	}
	return (0);
}

static int	do_corr_x(t_bresen *bres, t_pair *pair, int *x)
{
	if (*x == pair->x_end)
		return (1);
	bres->err = bres->err + bres->dy;
	*x = *x + bres->sx;
	return (0);
}

void	draw_line(t_window *win, t_pair *pair)
{
	int			x;
	int			y;
	t_bresen	bres;

	set_bresen_values(&bres, pair, &y, &x);
	while (1)
	{
		if (check_image_limits(win, x, y))
			my_mlx_pixel_put(win, x, y, pair->color_start);
		if (x == pair->x_end && y == pair->y_end)
			break ;
		bres.e2 = 2 * bres.err;
		if (bres.e2 >= bres.dy)
		{
			if (do_corr_x(&bres, pair, &x))
				break ;
		}
		if (bres.e2 <= bres.dx)
		{
			if (y == pair->y_end)
				break ;
			bres.err = bres.err + bres.dx;
			y = y + bres.sy;
		}
	}
}
