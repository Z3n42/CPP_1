/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaines <ibaines@student.42.urduli>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:38:41 by ibaines           #+#    #+#             */
/*   Updated: 2022/03/02 13:01:29 by ibaines          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <fcntl.h>

# include <unistd.h>

# include <string.h>

# include <stdlib.h>

# include "libft/libft.h"

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}				t_img;

typedef struct s_col
{
	void	*img;
	int		w;
	int		h;
	int		n;
}				t_col;

typedef struct s_wall
{
	t_img	u;
	t_img	l;
	t_img	r;
	t_img	b;
	t_img	t;

}				t_wall;

typedef struct s_player
{
	int		x;
	int		y;
	int		c;
	t_img	up;
	t_img	down;
	t_img	left;
	t_img	right;

}				t_player;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		n;
	int		i;
	t_img	up;
	t_img	down;
	t_img	l;
	t_img	r;

}				t_enemy;

typedef struct s_game
{
	void		*mlx;
	char		*print;
	int			mv;
	void		*win;
	int			u;
	int			ene;
	t_img		xl;
	t_img		xr;
	t_img		e_o;
	t_img		g;
	t_img		x;
	t_wall		w;
	t_col		col;
	t_player	p;
	t_img		e;
	t_img		end;
	t_enemy		*en;
	int			mw;
	int			mh;
	char		**map;
}				t_game;

int		ft_check_charac(t_game *g, int size);

int		ft_check_charac_b(t_game *g, int size);

int		ft_close_map_mid_check(char **map, int mh, int size);

int		ft_close_map_top_check(char **map, int size);

int		ft_close_map_bot_check(char **map, int mh, int size);

int		ft_close_map_check(char **map, int mh);

int		ft_str_len_check(char **map, int mh);

int		ft_map_exit_check(t_game *g);

int		ft_map_check(t_game *g);

int		ft_controlls(int keykode, t_game *g);

void	ft_move_right(t_game *g, int key);

void	ft_move_left(t_game *g, int key);

void	ft_move_down(t_game *g, int key);

void	ft_move_up(t_game *g, int key);

void	ft_i_w(t_game *game, void *img, int x, int y);

void	*ft_f_i(void *mlx_ptr, char *filename, int *width, int *height);

void	ft_check_en(t_game *g);

int		ft_close(t_game *g);

void	ft_str_img_e(char *str, t_game g, int j);

int		ft_read_file(t_game *g, char *name);

void	ft_str_img(char *str, t_game g, int j);

void	ft_data_img(t_game g, int mh, int flag);

void	ft_import_img(t_game *g);

void	ft_gameet_col(t_game *g, int key);

int		ft_mv_en(t_game *g, t_enemy *en);

void	ft_mv_en2(t_game *g, t_enemy *en);

int		ft_check_pos(t_game *game);

void	ft_init_en(t_game *g);

void	ft_gameet_col(t_game *g, int key);
#endif
