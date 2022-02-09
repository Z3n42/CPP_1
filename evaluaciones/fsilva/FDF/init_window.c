/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:28:02 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 15:41:48 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_total_y(t_pos *store, t_window *window)
{
	float	current_z;
	int		total_z;

	total_z = store->z_pos - store->z_neg;
	current_z = window->unit * total_z;
	return (current_z);
}

float	get_total_xy(t_pos *store, float unit, float iso_factor)
{
	float	current_x;
	float	current_y;

	current_x = unit * (store->y_max * iso_factor);
	current_y = unit * (store->x_max * iso_factor);
	return (current_y + current_x);
}

static void	set_max_dim_vert(t_pos *store, t_window *window)
{
	float	total_y;
	float	box_y;
	float	z_length;
	float	xy_length;

	total_y = get_total_y(store, window);
	z_length = total_y / window->unit;
	total_y = total_y + get_total_xy(store, window->unit, 0.4472);
	xy_length = (store->x_max + store->y_max) * 0.4472;
	box_y = (float)(window->y_max - (2 * window->margin));
	if (box_y >= total_y)
		window->y_max = (int)total_y + (2 * window->margin);
	else
		window->unit = box_y / (z_length + xy_length);
}

static void	set_max_dim_hori(t_pos *store, t_window *window)
{
	float	total_x;
	float	box_x;
	float	xy_length;

	total_x = get_total_xy(store, window->unit, 0.8944);
	xy_length = (store->x_max + store->y_max) * 0.8944;
	box_x = (float)(window->x_max - (2 * window->margin));
	if (box_x >= total_x)
		window->x_max = (int)total_x + (2 * window->margin);
	else
		window->unit = box_x / xy_length;
}

void	calculate_window_size(t_pos *store, t_window *window)
{
	window->x_max = 1920;
	window->y_max = 1080;
	window->unit = 40;
	window->margin = 100;
	set_max_dim_hori(store, window);
	set_max_dim_vert(store, window);
	window->x_center = window->x_max / 2;
	window->y_center = window->y_max / 2;
}
