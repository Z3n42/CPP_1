/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:44:13 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/14 15:08:02 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
#include "./minilibx/mlx.h"

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_aux{
	int			x;
	int			y;
	int			fd;
	char		*tab;
	int			**mat;
}	t_aux;

void	ft_draw(t_aux *aux);
void	ft_brasenham(t_data *img, int x, int y, int x1, int y1);

#endif
