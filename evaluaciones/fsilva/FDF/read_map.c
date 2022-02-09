/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:22:11 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 20:56:59 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"
#include "get_next_line_bonus.h"
#include <unistd.h>

void	set_height_maxmin(t_pos *store, int y, int x_max)
{
	int	x;

	x = 1;
	while (x <= x_max)
	{
		if (store->height[y][x] > store->z_pos)
			store->z_pos = store->height[y][x];
		if (store->height[y][x] < store->z_neg)
			store->z_neg = store->height[y][x];
		x++;
	}
}

void	set_height(t_pos *store, char **instr)
{
	int	y;

	y = 0;
	store->z_pos = 0;
	store->z_neg = 0;
	while (y < store->y_max)
	{
		store->height[y] = ft_split_to_int(instr[y], ' ', 10);
		set_height_maxmin(store, y, store->height[y][0]);
		y++;
	}
}

void	set_color(t_pos *store, char **instr)
{
	int	y;

	y = 0;
	while (y < store->y_max)
	{
		store->color[y] = ft_split_to_int(instr[y], ' ', 16);
		y++;
	}
}

void	process_map(t_pos *store, t_window *win, char **instr, size_t num_lines)
{
	store->y_max = (int)num_lines;
	store->height = (int **)malloc(sizeof(int *) * store->y_max);
	store->color = (int **)malloc(sizeof(int *) * store->y_max);
	if (store->height == NULL || store->color == NULL)
		error_exit(5);
	set_height(store, instr);
	store->x_max = store->height[0][0];
	set_color(store, instr);
	free_instr(instr, num_lines);
	store->angle = 0.0;
	store->proj = 'i';
	store->proj_angle = 26.565;
	name_map(win);
}

char	**read_instructions(char *map_path, size_t num_lines)
{
	size_t	i;
	int		fd;
	char	**instr;

	i = 0;
	instr = (char **)malloc(sizeof(char *) * (num_lines));
	if (instr == NULL)
		error_exit(6);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_exit(10);
	while (i < num_lines)
	{
		instr[i] = get_next_line(fd);
		if (instr[i] == NULL)
			error_exit(8);
		i++;
	}
	close(fd);
	return (instr);
}
