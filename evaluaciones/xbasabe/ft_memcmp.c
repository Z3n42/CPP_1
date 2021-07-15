/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:42:42 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/06/09 11:53:48 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned long	i;
	int				cmp;

	i = 0;
	while (i < n)
	{	
		cmp = *(unsigned char *)(str1 + i) - *(unsigned char *)(str2 + i);
		if (cmp != 0)
			return (cmp);
		i++;
	}
	return (0);
}
