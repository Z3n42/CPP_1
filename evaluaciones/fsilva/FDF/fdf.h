/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:06:56 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/08 15:41:08 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stddef.h>

// map info plus current angle of rotation
typedef struct s_pos
{
	int		y_max;
	int		x_max;
	int		z_pos;
	int		z_neg;
	int		**height;
	int		**color;
	float	angle;
	char	proj;
	float	proj_angle;
}			t_pos;

// mlx image structure
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

// window and origin/focus data
typedef struct s_window
{
	void	*mlxptr;
	void	*winptr;
	char	*name;
	int		x_max;
	int		y_max;
	int		x_center;
	int		y_center;
	int		x_focus;
	int		y_focus;
	int		z_focus;
	int		x_focus_base;
	int		y_focus_base;
	int		z_focus_base;
	float	x_origin;
	float	y_origin;
	float	x_origin_c;
	float	y_origin_c;
	float	unit;
	int		margin;
	t_data	*imgdata;
}			t_window;

// world coordinates
typedef struct s_wcoord
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_wcoord;

// screen coordinates
typedef struct s_scoord
{
	int	x;
	int	y;
	int	color;
}		t_scoord;

// pair of points to draw line
typedef struct s_pair
{
	int	x_start;
	int	y_start;
	int	color_start;
	int	x_end;
	int	y_end;
	int	color_end;
	int	end;
}		t_pair;

// bresenham algorithm variables
typedef struct s_bresen
{
	int	dx;
	int	dy;
	int	err;
	int	e2;
	int	sx;
	int	sy;	
}		t_bresen;

// struct for hooks
typedef struct s_hook
{
	t_pos		*store;
	t_window	*win;
}				t_hook;

void	add_to_pair(t_pair *pair, t_scoord *scoord);
void	calculate_window_size(t_pos *store, t_window *window);
void	cavalier(t_hook *param_hook);
int		close_button(t_hook *param_hook);
void	draw_image(t_pos *store, t_window *win, int focus);
void	draw_line(t_window *win, t_pair *pair);
void	draw_mesh(t_pos *store, t_window *win);
void	error_exit(int error_num);
void	free_height(t_pos *store);
void	free_color(t_pos *store);
void	free_instr(char **instr, size_t num_lines);
void	free_exits(t_pos *store, t_window *win);
int		ft_atoi_limits(const char *str, int base);
int		*ft_split_to_int(char *s, char c, int base);
char	*ft_substrf(char *s, unsigned int start, size_t len);
int		get_color(char *split, int base);
float	get_total_y(t_pos *store, t_window *window);
float	get_total_xy(t_pos *store, float unit, float iso_factor);
int		get_height(char *split, int base);
size_t	get_num_lines(char *map_path);
void	get_wcoord(t_pos *store, t_wcoord *wcoord_out, t_wcoord *wcoord_in);
void	get_scoord_iso(t_pos *store, t_window *win, t_wcoord *w_coord, \
						t_scoord *s_coord);
int		key_press(int keycode, t_hook *param_hook);
void	init_focus(t_pos *store, t_window *win);
void	init_display(t_pos *store, t_window *win);
void	my_mlx_pixel_put(t_window *win, int x, int y, int color);
int		mouse_click(int button, int x, int y, t_hook *param_hook);
char	*process_args(int argsc, char **argsv);
void	name_map(t_window *window);
void	process_map(t_pos *store, t_window *win, \
					char **instr, size_t num_lines);
void	proj_militar(t_hook *param_hook);
void	proj_iso(t_hook *param_hook);
char	**read_instructions(char *map_path, size_t num_lines);
void	reset_focus_on_origin(t_pos *store, t_window *win);
void	reset_origins_on_origins_c(t_window *win);
void	reset_origins_c_after_change_in_origins(t_window *win);
void	rotate(t_hook *param_hook, int keycode);
void	set_focus(t_pos *store, t_window *win, t_wcoord *wcoord);
void	set_origins(t_pos *store, t_window *win);

#endif
