/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:33:21 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/06 16:44:20 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>>

int	ft_check(char *str)
{
	int tab;
	int nrow;
	int ncol;
	char c;

	tab = open(str, O_RDONLY);
	if (tab == -1)
		return (0);
	else
	{
		row = -1;
		col = 0;
		while (read(tab, &c, sizeof(char)) > 0)
		{
			if (c == '\n')
				nrow++;
			if (row == 0 && c != '\n')
				ncol++;
		}
		ft_ardata(str, nrow, ncol);
		return (1);
	}
	close (tab);
}
