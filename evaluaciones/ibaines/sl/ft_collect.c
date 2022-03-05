/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:13:21 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 13:13:23 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "so_long.h"

void	ft_colup(t_game *g)
{
	g->mv++;
	g->map[g->p.y][g->p.x + 1] = 'P';
	g->map[g->p.y][g->p.x] = '0';
	g->p.c++;
	g->p.x++;
}

void	ft_coldown(t_game *g)
{
	g->mv++;
	g->map[g->p.y][g->p.x - 1] = 'P';
	g->map[g->p.y][g->p.x] = '0';
	g->p.c++;
	g->p.x--;
}

void	ft_colleft(t_game *g)
{
	g->mv++;
	g->map[g->p.y - 1][g->p.x] = 'P';
	g->map[g->p.y][g->p.x] = '0';
	g->p.c++;
	g->p.y--;
}

void	ft_colright(t_game *g)
{
	g->mv++;
	g->map[g->p.y + 1][g->p.x] = 'P';
	g->map[g->p.y][g->p.x] = '0';
	g->p.c++;
	g->p.y++;
}

void	ft_gameet_col(t_game *g, int key)
{
	if (g->map[g->p.y][g->p.x + 1] == 'C' && key == 0x02)
		ft_colup(g);
	if (g->map[g->p.y][g->p.x - 1] == 'C' && key == 0x00)
		ft_coldown(g);
	if (g->map[g->p.y - 1][g->p.x] == 'C' && key == 0x0D)
		ft_colleft(g);
	if (g->map[g->p.y + 1][g->p.x] == 'C' && key == 0x01)
		ft_colright(g);
	ft_data_img(*g, g->mh, 0);
}
