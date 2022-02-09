/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   focus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:39:08 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 20:54:13 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

/* reset_focus_base()
Sets the focus coordenates without angle correction (no rotation)
*/
static void	reset_focus_base(t_pos *store, t_window *win)
{
	float	angle;
	float	numer;
	float	denom;
	float	numer2;
	float	numer3;

	angle = store->angle;
	numer = win->x_focus * cos(angle) - win->z_focus * sin(angle);
	denom = (cos(angle) * cos(angle)) + (sin(angle) * sin(angle));
	win->x_focus_base = round(numer / denom);
	numer2 = win->z_focus + (win->x_focus_base * sin(angle));
	numer3 = win->x_focus - (win->x_focus_base * cos(angle));
	if (round(cos(angle)) != 0)
		win->z_focus_base = round(numer2 / cos(angle));
	else
		win->z_focus_base = round(numer3 / sin(angle));
}

/* reset_focus_on_origin()
Sets a new focus based on new origin coordinates
It considers only changes in axis x and axis z (keeps height constant...)
*/
void	reset_focus_on_origin(t_pos *store, t_window *win)
{
	float	comp1;
	float	comp2;
	float	iso_x;
	float	iso_y;

	iso_x = cos((store->proj_angle * M_PI) / 180);
	iso_y = sin((store->proj_angle * M_PI) / 180);
	comp1 = ((win->y_origin / win->unit) + win->y_focus) / iso_y;
	comp2 = win->x_origin / (iso_x * win->unit);
	win->z_focus = round((comp1 - comp2) / 2);
	win->x_focus = round((win->x_origin / (iso_x * win->unit)) + win->z_focus);
	reset_focus_base(store, win);
}

/* set_focus()
Sets the focus of the image based on world coordinates and a given  angle
*/
void	set_focus(t_pos *store, t_window *win, t_wcoord *fcoord)
{
	float		angle;

	angle = store->angle;
	win->x_focus = round(fcoord->x * cos(angle) + fcoord->z * sin(angle));
	win->y_focus = fcoord->y;
	win->z_focus = round(fcoord->z * cos(angle) - fcoord->x * sin(angle));
}

/* init_focus()
Initializes the focus to the center of the map (it centers on 3 axes)
*/
void	init_focus(t_pos *store, t_window *win)
{
	t_wcoord	fcoord;

	fcoord.x = store->x_max / 2;
	fcoord.y = (store->z_pos + store->z_neg) / 2;
	fcoord.z = store->y_max / 2;
	win->x_focus_base = fcoord.x;
	win->y_focus_base = fcoord.y;
	win->z_focus_base = fcoord.z;
	set_focus(store, win, &fcoord);
}
