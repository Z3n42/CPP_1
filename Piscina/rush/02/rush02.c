/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rus02.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 11:43:04 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/01 13:44:40 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "check_input.h"
/**
 * usaremos la variable int error para controlar los errores,
 * si error = 1 quiere decir que hay un error y finaliozara el programa,
 * si error = 0 nuestro programa seguira funcionando
 */

int 	main(int argc, char *argv[])
{
	int				error;
	unsigned int	num;

	/**Controlamos el numero de argumentos,
	* en caso de que tengamos un argumento argc = 2
	* y si argc = 3 tendremos 2 argumentos.
	*/
	error = 0;
	if (argc == 2)
	{
		error = ft_str_is_numeric(argv[1]);
		if (error == 0)
		{
			printf("Entramos en la uno\n");
			printf("%u\n", ft_get_num(argv[1]));
			//num = ft_get_num(argv[1]);
		}	
	}
	else if (argc == 3)
	{
		error = ft_str_is_numeric(argv[2]);
		if (error == 0)
		{
			printf("Entramos en la dos");
			//num = ft_get_num(argv[2])
		}
	}
	else
	{
		//ft_show_error();
	}
	if (error == 1)
	{
		//ft_show_error();
	}
	return (0);
}
