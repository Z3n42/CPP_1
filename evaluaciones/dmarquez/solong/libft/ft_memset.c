/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:03:56 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:58:26 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			pos;
	unsigned char	*src;

	src = b;
	pos = 0;
	while (len)
	{
		src[pos] = c;
		pos++;
		len--;
	}
	return (b);
}
