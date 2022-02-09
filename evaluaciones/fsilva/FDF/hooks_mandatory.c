/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mandatory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:58:16 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 17:02:43 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "./minilibx-linux/mlx.h"

int	key_press(int keycode, t_hook *param_hook)
{
	if (keycode == 0x35)
	{
		mlx_destroy_window(param_hook->win->mlxptr, param_hook->win->winptr);
		free_exits(param_hook->store, param_hook->win);
		exit(0);
	}
	return (0);
}

int	close_button(t_hook *param_hook)
{
	mlx_destroy_window(param_hook->win->mlxptr, param_hook->win->winptr);
	free_exits(param_hook->store, param_hook->win);
	exit(0);
	return (0);
}
