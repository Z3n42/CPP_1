/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarbaiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:50:25 by iarbaiza          #+#    #+#             */
/*   Updated: 2022/07/10 17:25:12 by iarbaiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	printmatrix(int matrix [4][4]);
int	validacion_preliminar(int col1up, int col2up, int col3up, int col4up);

int	main(int argc, char	**argv)

{
	if (argc != 17)
	{
		printf("Error");
		return (0);
	}
	int	col1up;
	col1up = atoi(argv[1]);
	int	col2up;
	col2up = atoi(argv[2]);
	int	col3up;
	col3up = atoi(argv[3]);
	int	col4up;
	col4up = atoi(argv[4]);
	int	matrix [4][4]
		matrix = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

	int	comb4 [4] = {1, 2, 3, 4};
	int	comb31 [4] = {2, 3, 4, 1};
	int	comb25 [4] = {3, 4, 1, 2};
	int	comb11 [4] = {4, 1, 2, 3};

	validacion_preliminar (col1up, col2up, col3up, col4up);
	if (col1up == 4 && col2up == 3 && col3up == 2 && col4up == 1)
	{
		while (col1up == 4)
		{
			int	l;
			if (l = 0; l < 4; l++)
			{
			matrix [l][0] = comb4 [l];
			}
		}
		if (col2up == 3)
		{
			int	k;
			while (k = 0; k < 4; k++)
			{
			matrix [k][1] = comb31 [k];
			}
		}
		if (col3up == 2)
		{
			int	j;
			while (j = 0; j < 4; j++)
			{
				matrix [j][2] = comb25 [j];
			}
		}
		if (col4up == 1)
		{
			int	p;
			while (p = 0; p < 4; p++)
			{
				matrix [p][3] = comb11 [p];
			}
		}
		printmatrix(matrix);
	}
	else
	{
		printf ("Error");
	}
}

int	printmatrix(int matrix[4][4])

{
	int	i;
	int	j;

	printf ("\n");
	while (i = 0; i < 4)
	{
		while (j = 0; j < 4)
		{
			printf ("%d ", matrix[i][j]);
			if (j == 3)
			{
				printf("\n");
			}
		}
		j++;
	}
	i++;
	return (0);
}

int	validacion_preliminar(int col1up, int col2up, int col3up, int col4up)
{
	if (col1up > 5 || col2up > 5 || col3up > 5 || col4up > 5)
	{
		printf("Error");
		return (0);
	}
	return (0);
}
