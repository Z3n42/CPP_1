/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:13:33 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/01 12:02:50 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

int	ft_check_pos(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->ene)
	{
		ft_mv_en(game, &game->en[i]);
		i++;
	}
	return (0);
}

void	ft_init_en(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->ene)
	{
		g->en[i].n = 1;
		g->en[i].i = 0;
		i++;
	}
}

void	ft_mv_en2(t_game *g, t_enemy *en)
{
	g->map[en->y][en->x + (1 * en->n)] = 'X';
	g->map[en->y][en->x] = '0';
	if (en->n == 1)
	{
		ft_i_w(g, g->xr.img, (en->x + 1) * 50, en->y * 50);
		ft_i_w(g, g->g.img, en->x * 50, en->y * 50);
	}
	if (en->n == -1)
	{
		ft_i_w(g, g->xl.img, (en->x - 1) * 50, en->y * 50);
		ft_i_w(g, g->g.img, en->x * 50, en->y * 50);
	}
	en->x = en->x + 1 * (en->n);
	if (g->map[en->y][en->x + (1 * en->n)] != 'P')
		if (g->map[en->y][en->x + (1 * en->n)] != '0')
			en->n = en->n * -1;
}

int	ft_mv_en(t_game *g, t_enemy *en)
{
	if (en->i % 20 == 0)
	{
		if (g->map[en->y][en->x + (1 * en->n)] == '0' \
				|| g->map[en->y][en->x + (1 * en->n)] == 'P')
			ft_mv_en2(g, en);
		if (en->x == g->p.x && en->y == g->p.y)
			ft_close(g);
	}
	if (en->n == -1)
		ft_i_w(g, g->xl.img, en->x * 50, en->y * 50);
	if (en->n == 1)
		ft_i_w(g, g->xr.img, en->x * 50, en->y * 50);
	en->i++;
	return (0);
}

void	ft_check_en(t_game *g)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (g->map[j] && j < g->mh)
	{
		while (g->map[j][i])
		{
			if (g->map[j][i] == 'X')
			{
				g->en[x].x = i;
				g->en[x].y = j;
				g->u = 1;
				x++;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
