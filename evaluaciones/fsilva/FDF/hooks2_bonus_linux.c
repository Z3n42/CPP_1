/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2_linux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:13:43 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 00:46:52 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "fdf.h"
#include "./minilibx-linux/mlx.h"
//#include "./mlx/mlx.h"

void	rotate(t_hook *param_hook, int keycode)
{
	if (keycode == 0xff51)
		param_hook->store->angle += ((90 * M_PI) / 180);
	else if (keycode == 0xff53)
		param_hook->store->angle -= ((90 * M_PI) / 180);
	draw_image(param_hook->store, param_hook->win, 1);
}

int	close_button(t_hook *param_hook)
{
	mlx_destroy_window(param_hook->win->mlxptr, param_hook->win->winptr);
	free_exits(param_hook->store, param_hook->win);
	exit(0);
	return (0);
}
