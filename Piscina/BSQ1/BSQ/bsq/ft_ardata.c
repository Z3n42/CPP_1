/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ardata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:05:01 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/06 19:55:12 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

void	ft_ardata(char *str, int col, int nrow)
{
	int		count;
	char	**tbl;

	tbl = malloc((col)*sizeof(char *));
	count = 0;
	while (count < nrow)
	{
		tbl[count] = malloc((nrow)* sizeof(char));
		count++;
	}
	ft_archarge(str, tbl, nrow);
}
