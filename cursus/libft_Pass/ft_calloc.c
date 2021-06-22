/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:15:55 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/09 18:20:00 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*array;
	size_t			max;
	size_t			counter;

	counter = 0;
	max = count * size;
	array = (unsigned char *)malloc(max);
	if (array == '\0')
		return (NULL);
	while (counter < max)
	{
		array[counter] = '\0';
		counter++;
	}
	return (array);
}
