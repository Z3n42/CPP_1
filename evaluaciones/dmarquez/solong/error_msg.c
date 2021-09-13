/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:54:33 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/04 15:23:45 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/ft_printf/ft_printf.h"

void	error_open_exit(void)
{
	ft_printf("ERROR: map can´t be opened");
	exit (1);
}

void	error_rec_exit(void)
{
	ft_printf("ERROR: map is not rectangular");
	exit (1);
}

void	error_big_exit(void)
{
	ft_printf("ERROR: map is too big");
	exit (1);
}

void	error_empty_exit(void)
{
	ft_printf("ERROR: map is empty!");
	exit (1);
}

void	error_inv_free(t_map	map)
{
	ft_printf("ERROR: Invalid map!");
	free(map.filled_map);
	exit (1);
}
