/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 12:05:41 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/07 17:03:32 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "gnl/get_next_line.h"
#include "libft/ft_printf/ft_printf.h"

int	map_widht(char	*map_file)
{
	char	*line;
	int		x_init;
	int		x;
	int		fd;

	line = NULL;
	fd = open(map_file, O_RDONLY);
	if (!fd || fd == -1)
		error_open_exit();
	line = get_next_line(fd);
	if (!line)
		error_empty_exit();
	x_init = ft_strlen(line) - 1;
	while (line != NULL)
	{
		x = ft_strlen(line);
		if (line[x - 1] == '\n')
			x--;
		if (x != x_init)
			error_rec_exit();
		line = get_next_line(fd);
	}
	if (x_init * 50 > 1920)
		error_big_exit();
	return (x_init);
}

int	map_hight(char	*map_file)
{
	char	*line;
	int		y;
	int		fd;

	y = 0;
	fd = open(map_file, O_RDONLY);
	if (!fd || fd == -1)
		error_open_exit();
	line = get_next_line(fd);
	if (!line)
		error_empty_exit();
	while (line != NULL)
	{
		line = get_next_line(fd);
		y++;
	}
	if (y * 50 > 1080)
		error_big_exit();
	return (y);
}

char	**fill_map(t_map	map, char	*map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	map.y = 0;
	while (map.map_h > map.y)
	{
		line = get_next_line(fd);
		map.x = 0;
		while (map.map_w > map.x)
		{
			map.filled_map[map.y][map.x] = line[map.x];
			map.x++;
		}
		map.filled_map[map.y][map.x] = '\0';
		map.y++;
	}
	map.filled_map[map.y] = NULL;
	close (fd);
	return (map.filled_map);
}

t_map	map_info(t_map	map, char	*map_file)
{
	map.x = 0;
	map.map_w = map_widht(map_file);
	map.map_h = map_hight(map_file);
	map.filled_map = (char **)malloc(sizeof(char *) * (map.map_h + 1));
	if (!map.filled_map)
		error_inv_free(map);
	while (map.map_h > map.x)
	{
		map.filled_map[map.x] = (char *)malloc(sizeof(char)
				* (map.map_w + 1));
		map.x++;
	}
	if (!map.filled_map)
		error_inv_free(map);
	map.filled_map = fill_map(map, map_file);
	if (!map.filled_map)
		error_inv_free(map);
	return (map);
}
