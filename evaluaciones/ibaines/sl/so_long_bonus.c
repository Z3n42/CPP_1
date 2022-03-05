/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:11:47 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 13:11:50 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minilibx/mlx.h"
#include <stdlib.h>
#include "so_long.h"
#include "libft/libft.h"
#include <fcntl.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	b = 0;
	a = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (str[a])
	{
		if (str[a + b] == to_find[b])
		{
			while (to_find[b])
			{
				b++;
				if (str[a + b] != to_find[b])
					break ;
			}
			if (b == (int)ft_strlen(to_find))
				return (str + a);
			b = 0;
		}
		a++;
	}
	printf("Error\nInvalid file, use *.ber\n");
	return (0);
}

void	ft_count_lines(t_game *g, int i, int fd)
{
	char	*ptr;

	ptr = "AA";
	while (1)
	{	
		if (ptr == NULL)
			break ;
		ptr = get_next_line(fd);
		free(ptr);
		i++;
	}
	i--;
	g->mh = i;
}

void	ft_fill_map(t_game *g, int i, int fd)
{
	char	*ptr;

	ptr = "AA";
	while (1)
	{
		ptr = get_next_line(fd);
		if (ptr == NULL || i == g->mh)
			break ;
		g->mw = (int)ft_strlen(ptr);
		g->map[i] = ptr;
		i++;
	}
}

int	ft_read_file(t_game *g, char *name)
{
	int		fd;
	int		i;

	i = 0;
	if (!ft_strstr(name, ".ber"))
		return (0);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		printf("Error\n Fallo de fd.");
	else
	{
		ft_count_lines(g, i, fd);
		close (fd);
		fd = open(name, O_RDONLY);
		g->map = (char **)malloc(sizeof(char *) * (g->mh + 1));
		if (!g->map)
			return (0);
		g->map[g->mh] = "\0";
		ft_fill_map(g, i, fd);
	}
	close (fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	g;

	g.ene = 0;
	if (argc < 2)
		return (0);
	if (ft_read_file(&g, argv[1]) == 0)
		return (0);
	if (ft_map_check(&g) == -1)
		return (-1);
	if (g.ene > 0)
		g.en = malloc(sizeof(t_game) * g.ene);
	ft_check_en(&g);
	ft_init_en(&g);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, (g.mw - 1) * 50, g.mh * 50, "so_long");
	ft_import_img(&g);
	ft_data_img(g, g.mh, 0);
	mlx_string_put(g.mlx, g.win, 10, 20, 0x00ff00, "0");
	mlx_hook(g.win, 2, 0, ft_controlls, &g);
	mlx_hook(g.win, 17, 0, ft_close, &g);
	if (g.u == 1)
		mlx_loop_hook(g.mlx, ft_check_pos, &g);
	mlx_loop(g.mlx);
	return (0);
}
