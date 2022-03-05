/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:10:29 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 13:10:31 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	ft_str_len_check(char **map, int mh)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(map[j]);
	while (map[j] && (int)j < mh)
	{
		if (i != ft_strlen(map[j]))
		{
			printf("Error\nEl mapa no es un rectángulo\n");
			return (1);
		}
		j++;
	}
	return (0);
}

void	ft_map_p(char *s, t_game *g, int *p, int j)
{
	int	i;

	i = 0;
	while (s[i] && i < g->mw - 1)
	{
		if (s[i] == 'P')
		{
			g->p.x = i;
			g->p.y = j;
			*p = *p + 1;
		}
		i++;
	}
}

void	ft_map_c(char *s, t_game *g, int *c, int *e)
{
	int	i;

	i = 0;
	while (s[i] && i < g->mw - 1)
	{
		if (s[i] == 'C')
			*c = *c + 1;
		if (s[i] == 'E')
			*e = *e + 1;
		if (s[i] == 'X')
			g->ene++;
		i++;
	}
}

int	ft_map_exit_check(t_game *g)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	i = 0;
	j = 0;
	e = 0;
	c = 0;
	p = 0;
	while (g->map[j] && j < g->mh)
	{
		ft_map_c(g->map[j], g, &c, &e);
		ft_map_p(g->map[j], g, &p, j);
		j++;
	}
	if (p == 1 && e >= 1 && c >= 1)
	{
		g->col.n = c;
		g->p.c = 0;
		return (0);
	}
	else
		return (1);
}

int	ft_map_check(t_game *g)
{
	int	size;

	size = (int)ft_strlen(g->map[0]);
	if (ft_str_len_check(g->map, g->mh) == 1)
		return (-1);
	if (ft_close_map_check(g->map, g->mh) == 1)
		return (-1);
	if (ft_map_exit_check(g) == 1)
	{
		printf("Error\nFalta un Coleccionable/Salida/personaje");
		return (-1);
	}
	if (ft_check_charac_b(g, size) == 1)
	{
		printf("Error\nCaracter incorrecto");
		return (-1);
	}
	else
		return (0);
}
