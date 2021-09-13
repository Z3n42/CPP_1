#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"

typedef struct s_map
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		map_w;
	int		map_h;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		collec;
	int		moves;
	char	**filled_map;
}			t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		img_w;
	int		img_h;
	int		x;
	int		y;
	int		bpp;
	int		linelen;
	int		endian;
	char	*floor;
	char	*pj;
	char	*wall;
	char	*collec;
	char	*exit;

}			t_img;

//////Map Info
t_map	map_info(t_map	map, char	*map_file);
int		map_widht(char	*map_file);
int		map_hight(char	*map_file);
char	**fill_map(t_map	map, char	*map_file);

/////Draw Map
void	check_map(t_map	map);
void	check_pj(t_map map);
void	check_exit_collec(t_map map);
void	check_char(t_map map);
void	check_wall(t_map map);
t_map	draw_map(t_map	map);
void	draw_floor(t_map	map);
t_map	draw_pj(t_map	map);
void	draw_wall(t_map	map);
int		draw_collec(t_map	map);
void	draw_exit(t_map	map);

//////Hooks
int		close_game(int keycode, t_map *map);
int		close_game_x(t_map *map);
int		move(int	keycode, t_map	*map);

/////Utils
t_img	init_img(void);
t_map	init_map(void);

/////Error msg
void	error_open_exit(void);
void	error_big_exit(void);
void	error_rec_exit(void);
void	error_empty_exit(void);
void	error_inv_free(t_map	map);
#endif
