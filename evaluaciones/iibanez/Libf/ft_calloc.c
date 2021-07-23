/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:12:37 by iibanez-          #+#    #+#             */
/*   Updated: 2021/06/08 19:49:14 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*dest;
	unsigned int	t_size;
	unsigned int	i;

	t_size = nmemb * size;
	dest = malloc(t_size);
	if (!(dest))
		return (NULL);
	i = 0;
	while (t_size--)
	{
		dest[i] = 0;
		i++;
	}
	return ((void *)dest);
}
