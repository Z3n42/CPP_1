/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:12:02 by ingonzal          #+#    #+#             */
/*   Updated: 2021/12/09 15:15:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_bg{
	int		width;
	int		height;
	char	bgc;
	char	c;
	float	x;
	float	y;
	float	radius;
	char	circle;
	char 	**array;
}	t_bg;

void	ft_free(t_bg *bg)
{
	int i;

	i = bg->height;
	while (i >= 0)
	{
		free(bg->array[i]);
		i--;	
	}
	free(bg->array);
}

void	ft_print(t_bg *bg)
{
	int		w;
	int		h;

	h = 0;
	while (h < bg->height)
	{
		w = 0; 
		while (w < bg->width)
		{
			write(1, &bg->array[h][w], 1);
			w++;
		}
		write(1, "\n", 1);
		h++;
	}
}

void	ft_charge(t_bg *bg)
{	
	int		w;
	int		h;
	float	xa;
	float	ya;

	xa = bg->x;
	ya = bg->y;
	h = 0;
	while (h < bg->height)
	{
		w = 0; 
		while (w < bg->width)
		{
			if (bg->c == 'c')
			{
				if (((sqrtf((xa - w) * (xa - w) + (ya - h) * (ya - h))) <= bg->radius))
				{
					if (bg->radius - (sqrtf((xa - w) * (xa - w) + (ya - h) * (ya - h))) < 1)
						bg->array[h][w] = bg->circle;
				}
			}
			else
			{
				if (((sqrtf((xa - w) * (xa - w) + (ya - h) * (ya - h))) <= bg->radius))
					bg->array[h][w] = bg->circle;

			}
			w++;
		}
		h++;
	}
}

void	ft_backgr(t_bg *bg)
{
		int		w;
		int		h;

		bg->array = (char **)malloc((bg->height + 1) * sizeof(char *));
		h = 0;
		while (h < bg->height)
		{
			bg->array[h] = (char *)malloc((bg->width + 1) * sizeof(char));	
			w = 0; 
			while (w < bg->width)
			{
				bg->array[h][w] = bg->bgc;
				w++;
			}
			bg->array[h][w] = '\0';
			h++;
		}
		bg->array[h] = NULL;
}

int	main(int argc, char **argv)
{
	t_bg		bg;
	FILE		*of;
	int			res;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	of = fopen(argv[1], "r");
	if (!of)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	res = fscanf(of, "%d %d %c\n", &bg.width, &bg.height, &bg.bgc);
	if(res != 3 || bg.width <= 0 || bg.width > 300 || bg.height <= 0 || bg.height > 300)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	else
		ft_backgr(&bg);	
	res = 0;
	while (res != -1)
	{
		res = fscanf(of, "%c %f %f %f %c\n", &bg.c, &bg.x, &bg.y, &bg.radius, &bg.circle);
		if (res == -1)
		{
			fclose(of);
			ft_print(&bg);
			ft_free(&bg);
			return (0);
		}
		if ((res != 5 && res != -1) || (bg.c != 'c' && bg.c != 'C') || (bg.radius <= 0))
		{
			write(1, "Error: Operation file corrupted\n", 32);
			ft_free(&bg);
			return (1);
		}
		ft_charge(&bg);
	}
	fclose(of);
	ft_print(&bg);
	ft_free(&bg);
	return (0);
}
