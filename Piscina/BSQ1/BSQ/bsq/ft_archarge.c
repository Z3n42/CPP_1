/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_archarge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:41:37 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/06 19:49:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

void	ft_archarge(char *str, char **tbl, int nrow)
{
	int		table;
	char	c;
	int		col;
	int		row;
	char	cont[4];

	table = open(str, O_RDONLY);
	col = 0;
	row = -1;
	while (read(table, &c, sizeof(char)) > 0)
	{
		if (row < nrow)
		{
			if (row == -1)
			{
				if (c == '\n')
				{
					row++;
					col = 0;
				}
				else
				{
					cont[col] = c;
					if (col > 3)
					{
						ft_tbl_error();
					}
					row++;
				}
			}
			else
			{
				if (c == '\n')
				{
					tbl[row][col] = c;
					row++;
					col = 0;
				}
				else
				{
					tbl[row][col] = c;
					col++;
				}
			}
		}
	}
	close (table);
}
