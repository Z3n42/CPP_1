/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:33:15 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/06/10 10:02:08 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc (size_t count, size_t size)
{
	unsigned char	*aux;
	size_t			i;

	aux = (void *)malloc(size * count);
	if (aux == NULL)
		return (NULL);
	i = size * count;
	return (ft_memset(aux, 0, i));
}
