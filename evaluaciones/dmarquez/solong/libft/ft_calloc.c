/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:43:06 by dmarquez          #+#    #+#             */
/*   Updated: 2021/07/23 17:33:27 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*str;

	str = malloc(count * size);
	if (str == 0)
		return (0);
	ft_memset(str, 0, (count * size));
	return (str);
}
