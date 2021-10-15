/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:03:42 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/13 10:28:51 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/gnl.h"
# include "./libft/libft.h"
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map{
	char	**map;
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	int		movements;
	int		y;
	int		x;
	int		old_x;
	int		old_y;
	int		new_x;
	int		new_y;
	void	*i_f;
	void	*i_w;
	void	*i_h;
	void	*i_c;
	void	*i_d;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	char	*hero;
	char	*wall;
	char	*floor;
	char	*chest;
	char	*door;
	int		i_x;
	int		i_y;
	int		t_c;
	int		c_c;
	int		min_x;
	int		min_e;
	int		min_c;
	char	*argv;
}			t_map;

void	ft_create_map(t_map *map);
void	ft_define_img_route(t_map *map);
int		ft_keyboard(int keycode, t_map *map);
void	ft_find_player(t_map *map);
void	ft_map_init(t_map *map);
void	ft_map_loop(t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_right(t_map *map);
void	ft_move(t_map *map);
int		ft_close_window(t_map *map);
void	ft_end_game(t_map *map);
void	ft_check_errors(t_map *map);
int		ft_check_objs(t_map *map);
int		ft_check_borders(t_map *map);
int		ft_check_box(t_map *map);
void	ft_free_map(t_map *map);
void	ft_check_door(t_map *map);
void	ft_close_error(void);
#endif
