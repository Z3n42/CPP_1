/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_linux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:46:46 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 14:20:19 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "./minilibx-linux/mlx.h"

void	free_instr(char **instr, size_t num_lines)
{
	size_t	i;

	i = 0;
	while (i < num_lines)
	{
		free(instr[i]);
		i++;
	}
	free(instr);
}

void	free_color(t_pos *store)
{
	int	y;

	y = 0;
	while (y < store->y_max)
	{
		free(store->color[y]);
		y++;
	}
	free(store->color);
}

void	free_height(t_pos *store)
{
	int	y;

	y = 0;
	while (y < store->y_max)
	{
		free(store->height[y]);
		y++;
	}
	free(store->height);
}

void	free_exits(t_pos *store, t_window *win)
{
	mlx_destroy_image(win->mlxptr, win->imgdata->img);
	mlx_destroy_display(win->mlxptr);
	free(win->mlxptr);
	free(win->imgdata);
	free_color(store);
	free_height(store);
}
