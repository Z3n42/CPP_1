/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:17:59 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/07 14:16:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./minilibx/mlx.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
#include <fcntl.h>

int	ft_xcount(char const *s, char c)
{
	int	counter;
	int	pos;

	counter = 0;
	pos = 0;
	while (s[counter])
	{
		if (s[counter] == c && s[counter + 1] != c)
			pos++;
		counter++;
	}
	/* printf("S[counter] = %c\n", s[counter - 1]); */
	if(s[counter - 1] == ' ')
		return (pos);
	else
		return (pos + 1);
}

int	**ft_matrix(int fd, int x, int y)
{
	char	**tbl;
	char	*str;
	int		**mat;
	int		i;
	int		j;

	mat = (int **)malloc(y * sizeof(int *));
	j = 0;
	while (get_next_line(fd, &str))
	{
		tbl = ft_split(str, ' ');
		free(str);
		i = 0;
		mat[j] = (int *)malloc(x * sizeof(int));
		while(tbl[i])
		{
			mat[j][i] = ft_atoi(tbl[i]);
			free(tbl[i]);
			i++;
		}
		free(tbl);
		j++;
	}
	free(str);
	return(mat);
}

void	ft_open(t_aux *aux, char *argv)
{
	/* int		i; */
	/* int		j; */

	aux->fd = open(argv, O_RDONLY);
	get_next_line(aux->fd, &aux->tab);
	aux->x = ft_xcount(aux->tab, ' ');
	free(aux->tab);
	printf("X = %d\n", aux->x);
	/* i = 0; */
	aux->y = 1;
	while (get_next_line(aux->fd, &aux->tab))
	{
		free(aux->tab);
		aux->y++;
	}
	free(aux->tab);
	printf("Y = %d\n", aux->y);
	close(aux->fd);
}

int	main(int argc, char **argv)
{
	t_aux	aux;
	int 	i;
	/* int		j; */

	if(argc < 1)
		return(0);
	ft_open(&aux, argv[1]);
	aux.fd = open(argv[1], O_RDONLY);
	aux.mat = ft_matrix(aux.fd, aux.x, aux.y);
	ft_draw(&aux);
	i = 0;
	while(i < aux.y)
	{
		/* j = 0; */
		/* while(j < aux.x) */
		/* { */
		/* 	printf("%d", aux.mat[i][j]); */
		/* 	j++; */
		/* } */
		free(aux.mat[i]);
		/* printf("\n"); */
		i++;
	}
	free(aux.mat);
	/* system("leaks pruebafdf"); */
}
