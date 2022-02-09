/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:43:45 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 19:48:22 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

/*
reset_unit_projection_y()
Resets win->unit if the total_y component is bigger than the win->y_max
*/
static void	reset_unit_projection_y(t_pos *store, t_window *win)
{
	float	total_y;
	float	z_length;
	float	xy_length;
	float	proj_angle;

	proj_angle = store->proj_angle;
	total_y = get_total_y(store, win);
	z_length = total_y / win->unit;
	total_y = total_y + \
			get_total_xy(store, win->unit, sin((proj_angle * M_PI) / 180));
	xy_length = (store->x_max + store->y_max) * sin(proj_angle * M_PI / 180);
	if (win->y_max < total_y)
		win->unit = (win->y_max / (z_length + xy_length));
}

static void	reset_unit_projection_x(t_pos *store, t_window *win)
{
	float	total_x;
	float	xy_length;
	float	proj_angle;

	proj_angle = store->proj_angle;
	total_x = get_total_xy(store, win->unit, cos((proj_angle * M_PI) / 180));
	xy_length = (store->x_max + store->y_max) * cos((proj_angle * M_PI) / 180);
	if (win->x_max < total_x)
		win->unit = (win->x_max / xy_length);
}

static void	reset_projection(t_hook *param_hook)
{
	reset_unit_projection_y(param_hook->store, param_hook->win);
	reset_unit_projection_x(param_hook->store, param_hook->win);
	reset_origins_on_origins_c(param_hook->win);
	reset_focus_on_origin(param_hook->store, param_hook->win);
	draw_image(param_hook->store, param_hook->win, 0);
}

void	proj_militar(t_hook *param_hook)
{
	param_hook->store->proj_angle = 45;
	param_hook->store->proj = 'c';
	reset_projection(param_hook);
}

void	proj_iso(t_hook *param_hook)
{
	param_hook->store->proj_angle = 26.565;
	param_hook->store->proj = 'i';
	reset_projection(param_hook);
}
