/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:12:15 by ingonzal          #+#    #+#             */
/*   Updated: 2021/05/06 19:46:03 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

int	ft_check (char *str);

int	main(int argc, char *argv[])
{
	int	n_arg;
	int	go;

	if (argc == 1)
	{
		write (1, "Mapa", 4);
	}
	else
	{
		n_arg = 1;
		go = 1;
		while (n_arg <= argc -1)
		{
			go = ft_check (argv[n_arg]);
			n_arg++;
			if (go == 0)
				ft_tbl_error();
			else
				write (1, "All rigth", 9);
		}
	}
}
