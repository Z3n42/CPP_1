/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:00:58 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/02 21:21:23 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <unistd.h>

int	ft_size(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
}

void	ft_show_error(void)
{
	write(1, &"Error", 5);
}

void	ft_set_dict_name(char *dest, char *src)
{
	char	*dest_aux;
	char	*src_aux;

	dest_aux = dest;
	src_aux = src;
	while (*dest_aux)
	{
		dest_aux++;
	}
	while (*src_aux)
	{
		*dest_aux = *src_aux;
		dest_aux++;
		src_aux++;
	}
	*dest_aux = '\0';
}
