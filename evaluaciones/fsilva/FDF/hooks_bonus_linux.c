/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:58:16 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 14:23:59 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "./minilibx-linux/mlx.h"

/* zoom()
Modify the scale (unit) and reset the origin and the focus 
with the new units.
*/
static void	zoom(t_hook *p_hook, int keycode)
{
	float	factor;

	factor = 1;
	if (keycode == 0xff54 || keycode == 5)
		factor = 0.9;
	else if (keycode == 0xff52 || keycode == 4)
		factor = 1.1;
	p_hook->win->unit = p_hook->win->unit * factor;
	if (p_hook->win->unit < 1)
		p_hook->win->unit = 1;
	reset_origins_on_origins_c(p_hook->win);
	reset_focus_on_origin(p_hook->store, p_hook->win);
	draw_image(p_hook->store, p_hook->win, 0);
}

static void	center_click(t_pos *store, t_window *win, int x, int y)
{
	int	x_offset;
	int	y_offset;

	x_offset = x - win->x_center;
	win->x_origin = win->x_origin + x_offset;
	y_offset = y - win->y_center;
	win->y_origin = win->y_origin + y_offset;
	reset_origins_c_after_change_in_origins(win);
	reset_focus_on_origin(store, win);
	draw_image(store, win, 0);
}

int	key_press(int keycode, t_hook *param_hook)
{
	if (keycode == 0xFF1B)
	{
		mlx_destroy_window(param_hook->win->mlxptr, param_hook->win->winptr);
		free_exits(param_hook->store, param_hook->win);
		exit(0);
	}
	else if (keycode == 0xff54 || keycode == 0xff52)
		zoom(param_hook, keycode);
	else if (keycode == 0xff51 || keycode == 0xff53)
		rotate(param_hook, keycode);
	else if (keycode == 0x6d)
		proj_militar(param_hook);
	else if (keycode == 0x69)
		proj_iso(param_hook);
	return (0);
}

int	mouse_click(int button, int x, int y, t_hook *param_hook)
{
	if (button == 4 || button == 5)
		zoom(param_hook, button);
	else if (button == 1)
		center_click(param_hook->store, param_hook->win, x, y);
	return (0);
}
