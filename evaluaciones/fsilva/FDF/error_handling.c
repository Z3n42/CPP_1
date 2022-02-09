/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:05:37 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/07 20:43:17 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdlib.h>

void	error_exit(int error_num)
{
	if (error_num == 1)
		write(2, "Error malloc pair\n", 18);
	else if (error_num == 2)
		write(2, "Error atoi limits\n", 18);
	else if (error_num == 3)
		write(2, "Error split into int\n", 21);
	else if (error_num == 4)
		write(2, "Error malloc imgdata\n", 21);
	else if (error_num == 5)
		write(2, "Error malloc store\n", 19);
	else if (error_num == 6)
		write(2, "Error malloc instr\n", 19);
	else if (error_num == 7)
		write(2, "Error opening file\n", 19);
	else if (error_num == 8)
		write(2, "Error reading gnl\n", 18);
	else if (error_num == 9)
		write(2, "Error map_path\n", 15);
	else if (error_num == 10)
		write(2, "Error opening file gnl\n", 23);
	exit(0);
}
