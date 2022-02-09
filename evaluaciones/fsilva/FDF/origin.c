/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   origin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:51:05 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 17:37:12 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>

/* 
win->x_origin is the origin in pixels
win->x_origin_c is the origin in coordinates => component x (x and z)
origin = origin_c * unit;
*/
static void	set_origins_c(t_pos *store, t_window *win)
{
	float	angle;
	int		comp_x;
	int		comp_y;

	angle = store->proj_angle;
	comp_x = win->x_focus - win->z_focus;
	comp_y = win->x_focus + win->z_focus + 1;
	win->x_origin_c = comp_x * cos((angle * M_PI) / 180);
	win->y_origin_c = (comp_y * sin((angle * M_PI) / 180)) - win->y_focus;
}

void	reset_origins_on_origins_c(t_window *win)
{
	win->x_origin = win->x_origin_c * win->unit;
	win->y_origin = win->y_origin_c * win->unit;
}

void	set_origins(t_pos *store, t_window *win)
{
	set_origins_c(store, win);
	reset_origins_on_origins_c(win);
}

void	reset_origins_c_after_change_in_origins(t_window *win)
{
	win->x_origin_c = win->x_origin / win->unit;
	win->y_origin_c = win->y_origin / win->unit;
}
