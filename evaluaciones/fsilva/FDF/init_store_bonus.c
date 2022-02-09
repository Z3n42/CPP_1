/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_store_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 21:03:33 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 14:21:35 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./libft/libft.h"
#include "./minilibx-linux/mlx.h"

static void	init_image_first(t_pos *store, t_window *win)
{
	win->imgdata = (t_data *)malloc(sizeof(t_data));
	if (win->imgdata == NULL)
		error_exit(4);
	ft_memset(win->imgdata, 0, sizeof(t_data));
	draw_image(store, win, 0);
}

static void	init_window(t_pos *store, t_window *win)
{
	calculate_window_size(store, win);
	win->winptr = mlx_new_window(win->mlxptr, \
							win->x_max, win->y_max, win->name);
	init_focus(store, win);
	set_origins(store, win);
}

void	init_display(t_pos *store, t_window *win)
{	
	t_hook	param_hook;

	param_hook.store = store;
	param_hook.win = win;
	win->mlxptr = mlx_init();
	init_window(store, win);
	init_image_first(store, win);
	mlx_hook(win->winptr, 2, 1L << 0, key_press, &param_hook);
	mlx_hook(win->winptr, 4, 1L << 2, mouse_click, &param_hook);
	mlx_hook(win->winptr, 17, 1L << 17, close_button, &param_hook);
	mlx_loop(win->mlxptr);
}
