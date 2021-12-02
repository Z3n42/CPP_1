/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:12:02 by ingonzal          #+#    #+#             */
/*   Updated: 2021/12/02 17:45:37 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_bg{
	int		width;
	int		height;
	char	bgc;
}	t_bg;

typedef struct s_print{
	char		c;
	float		x;
	float		y;
	float		radius;
	char		circle;
}	t_print;

void	ft_charge(t_bg *bg, t_print *pr, char **array)
{

}

void	ft_backgr(t_bg *bg, t_print *pr)
{
		char 	**array;
		int		w;
		int		h;

		array = (char **)malloc((bg->height + 1) * sizeof(char *));
		h = 0;
		while (h < bg->height)
		{
			array[h] = (char *)malloc((bg->width + 1) * sizeof(char));	
			w = 0; 
			while (w < bg->width)
			{
				array[h][w] = bg->bgc;
				w++;
			}
			array[h][w] = '\0';
			h++;
		}
		array[h] = NULL;
		ft_charge(bg, pr, array);
}

int	main(int argc, char **argv)
{
	t_bg		bg;
	t_print		pr;
	FILE		*of;
	int			count;

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
	fscanf(of, "%d %d %c\n", &bg.width, &bg.height, &bg.bgc);
	if(bg.width < 0 || bg.width <= 300 || bg.height < 0 || bg.width <= 300 || !bg.bgc)
		return (1);
	else
		ft_backgr(&bg, &pr);	
	while (fscanf(of, "%c %f %f %f %c\n", &pr.c, &pr.x, &pr.y, &pr.radius, &pr.circle) = 6)
	{
		ft_backgr(&bg, &pr);	
		if (!pr.c || !pr.x || !pr.y || !pr.radius || !pr.circle)
			return (1);
		count++;
	}
	fclose(of);
	return (0);
}
