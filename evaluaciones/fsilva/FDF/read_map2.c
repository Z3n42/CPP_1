/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:40:47 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 20:17:21 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "fdf.h"
#include "get_next_line_bonus.h"

char	*process_args(int argsc, char **argsv)
{
	if (argsc != 2)
		error_exit(9);
	return (argsv[1]);
}

void	name_map(t_window *window)
{
	window->name = "FDF";
}

size_t	get_num_lines(char *map_path)
{
	int		status;
	char	*line;
	size_t	count;
	int		fd;

	status = 1;
	line = NULL;
	count = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error_exit(7);
	while (status)
	{
		line = get_next_line(fd);
		if (line == NULL)
			status = 0;
		else
		{
			free(line);
			count++;
		}
	}
	close(fd);
	return (count);
}
