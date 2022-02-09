/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:15:19 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/06 13:13:51 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

int	main(int argsc, char **argsv)
{
	size_t		num_lines;
	char		*map_path;
	char		**instr;
	t_pos		store;
	t_window	window;

	map_path = process_args(argsc, argsv);
	num_lines = get_num_lines(map_path);
	instr = read_instructions(map_path, num_lines);
	process_map(&store, &window, instr, num_lines);
	init_display(&store, &window);
	free_exits(&store, &window);
	return (0);
}
