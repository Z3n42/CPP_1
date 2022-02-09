/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 19:17:46 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 20:54:45 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	get_wcoord(t_pos *store, t_wcoord *wcoord_o, t_wcoord *wcoord_in)
{
	float	angle;

	angle = store->angle;
	wcoord_o->z = store->height[wcoord_o->y][wcoord_o->x];
	wcoord_in->y = wcoord_o->z;
	wcoord_in->x = round(wcoord_o->x * cos(angle) + wcoord_o->y * sin(angle));
	wcoord_in->z = round(-wcoord_o->x * sin(angle) + wcoord_o->y * cos(angle));
	wcoord_in->color = store->color[wcoord_o->y][wcoord_o->x];
}

void	get_scoord_iso(t_pos *store, t_window *win, t_wcoord *wcoord, \
						t_scoord *scoord)
{
	float	corr_x;
	float	corr_y;
	float	comp_y;
	float	comp_x;

	corr_x = win->x_center - win->x_origin;
	corr_y = win->y_center - win->y_origin;
	comp_y = (((wcoord->x + wcoord->z) * sin((store->proj_angle * M_PI) / 180)) \
			- wcoord->y);
	comp_x = (wcoord->x - wcoord->z) * cos((store->proj_angle * M_PI) / 180);
	scoord->x = round((comp_x * win->unit) + corr_x);
	scoord->y = round((comp_y * win->unit) + corr_y);
	scoord->color = wcoord->color;
}

void	add_to_pair(t_pair *pair, t_scoord *scoord)
{
	if (pair->end == 0)
	{
		pair->x_start = scoord->x;
		pair->y_start = scoord->y;
		pair->color_start = scoord->color;
	}
	else if (pair->end == 1)
	{
		pair->x_end = scoord->x;
		pair->y_end = scoord->y;
		pair->color_end = scoord->color;
	}
}
