/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerwig- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:24:46 by dgerwig-          #+#    #+#             */
/*   Updated: 2021/05/03 20:29:15 by dgerwig-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	range = malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		*(range + i) = min;
		min++;
		i++;
	}
	return (range);
}
