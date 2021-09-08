/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brasenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:28:14 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/06 15:00:50 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./minilibx/mlx.h"
#include "./libft/libft.h"

void ft_brasenham(t_data *img, int x, int y, int x1, int y1)
{
	int	dx;
	int dy;
	int m;
	int p;


	dx = x1 - x;
	dy = y1 - y;		
	m = dy/dx;
	p = 2 * (dy - dx);
	my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
	while(x < x1)
	{
		if (p <= 0)
		{
			x++;
			p = p+(2*y);
		}
		else
		{
			x++;
			y++;
			p = p+(2*y)+(2*x);
		}
		my_mlx_pixel_put(&img, x, y, 0x00FFFFFF);
	}
}
