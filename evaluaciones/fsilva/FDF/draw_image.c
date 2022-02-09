/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:10:35 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 14:19:28 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx-linux/mlx.h"

static void	init_image(t_window *win)
{
	if (win->imgdata->img != NULL)
		mlx_destroy_image(win->mlxptr, win->imgdata->img);
	win->imgdata->img = mlx_new_image(win->mlxptr, win->x_max, win->y_max);
	win->imgdata->addr = mlx_get_data_addr(win->imgdata->img, \
					&win->imgdata->bits_per_pixel, &win->imgdata->line_length, \
					&win->imgdata->endian);
}

void	draw_image(t_pos *store, t_window *win, int focus)
{
	t_wcoord	fcoord;

	fcoord.x = win->x_focus_base;
	fcoord.z = win->z_focus_base;
	fcoord.y = win->y_focus_base;
	init_image(win);
	if (focus == 1)
	{
		set_focus(store, win, &fcoord);
		set_origins(store, win);
	}
	draw_mesh(store, win);
	mlx_put_image_to_window(win->mlxptr, win->winptr, win->imgdata->img, 0, 0);
}
