/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:54:58 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 10:19:30 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "minilibx/mlx.h"

void	ft_i_w(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	*ft_f_i(void *mlx_ptr, char *filename, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx_ptr, filename, width, height));
}

int	ft_close(t_game *g)
{
	mlx_destroy_window(g->mlx, g->win);
	exit(0);
}

void	ft_import_img(t_game *g)
{
		g->g.img = ft_f_i(g->mlx, "T/g", &g->g.w, &g->g.h);
		g->e.img = ft_f_i(g->mlx, "T/Exit", &g->e.w, &g->e.h);
		g->w.u.img = ft_f_i(g->mlx, "T/W_u", &g->w.u.w, &g->w.u.h);
		g->w.b.img = ft_f_i(g->mlx, "T/W_b", &g->w.b.w, &g->w.b.h);
		g->w.l.img = ft_f_i(g->mlx, "T/W_l", &g->w.l.w, &g->w.l.h);
		g->w.t.img = ft_f_i(g->mlx, "T/T", &g->w.t.w, &g->w.t.h);
		g->col.img = ft_f_i(g->mlx, "T/C", &g->col.w, &g->col.h);
		g->p.down.img = ft_f_i(g->mlx, "T/l_d", &g->p.down.w, &g->p.down.h);
		g->p.up.img = ft_f_i(g->mlx, "T/l_u", &g->p.up.w, &g->p.up.h);
		g->p.left.img = ft_f_i(g->mlx, "T/l_l", &g->p.left.w, &g->p.left.h);
		g->p.right.img = ft_f_i(g->mlx, "T/l_r", &g->p.right.w, &g->p.right.h);
		g->e_o.img = ft_f_i(g->mlx, "T/E_o", &g->e_o.w, &g->e_o.h);
		g->end.img = ft_f_i(g->mlx, "T/Win", &g->end.w, &g->end.h);
		g->xl.img = ft_f_i(g->mlx, "T/E_l", &g->xl.w, &g->xl.h);
		g->xr.img = ft_f_i(g->mlx, "T/E_r", &g->xr.w, &g->xr.h);
}

void	ft_data_img(t_game g, int mh, int flag)
{
	int	j;

	j = 0;
	while (j < mh)
	{
		if (flag == 0)
			ft_str_img(g.map[j], g, j);
		if (flag == 1)
			ft_str_img_e(g.map[j], g, j);
		j++;
	}
}
