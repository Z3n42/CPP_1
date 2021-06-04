/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_archarge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:41:37 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/06 16:44:13 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void ft_archarge.c(char *str, char **tbl, int nrow)
{
	int		tbl;
	char	c;
	int		col;
	int		row;
	char	cont[4];
	
	map = open(str, O_RDONLY);
	col = 0;
	row = -1;
	while (read(map, &c, sizeof(char)) > 0)
	{
		if (row < nrow)
		{
			if (row = -1)
			{
				
			}
			else
			{
			
			}
		}
	}
		
}
