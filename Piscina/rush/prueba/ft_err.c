/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:21:42 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/25 19:50:46 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_param_err(char);
char	ft_length_err(char);
char	ft_odd_err(char);
char	ft_even_err(char);

int	ft_err(int argc, char *argv)
{
	if (ft_param_err(argc) == 1)
		write(1, " error de parametro ", 19);
	else if (ft_length_err(argv) == 1)
		write(1, " error de valores ", 17);
	else if (ft_odd_err(argv) == 1)
		write(1, " error de caracter sp ", 21);
	else if (ft_even_err(argv) == 1)
		write(1, " error de caracter num ", 22);
}
