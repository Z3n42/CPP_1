/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperales <jperales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:38:51 by jperales          #+#    #+#             */
/*   Updated: 2021/08/30 19:37:53 by jperales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t	size)
{
	void	*mem;

	mem = (void *)malloc(count * size);
	if (!mem)
		return (0);
	ft_memset(mem, 0, count * size);
	return (mem);
}
