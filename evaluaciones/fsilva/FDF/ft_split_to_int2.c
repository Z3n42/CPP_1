/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_to_int2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:43:12 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/06 23:50:20 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/libft.h"
#include "fdf.h"

static void	to_upper_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

static size_t	get_comma_position(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			return (i);
		i++;
	}
	return (i);
}

int	get_color(char *split, int base)
{	
	size_t	pos_comma;
	int		num;

	if (ft_strchr(split, ','))
	{
		pos_comma = get_comma_position(split);
		split = ft_substrf(split, pos_comma + 3, 6);
		to_upper_str(split);
		num = ft_atoi_limits(split, base);
		free(split);
		return (num);
	}
	else
	{
		free(split);
		return (0x008D9F);
	}
}

int	get_height(char *split, int base)
{	
	size_t	pos_comma;
	int		num;

	if (ft_strchr(split, ','))
	{
		pos_comma = get_comma_position(split);
		split = ft_substrf(split, 0, pos_comma);
	}
	num = ft_atoi_limits(split, base);
	free(split);
	return (num);
}
