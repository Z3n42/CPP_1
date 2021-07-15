/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:31:30 by mvillega          #+#    #+#             */
/*   Updated: 2021/06/02 19:31:31 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* working okay */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*as1;
	const unsigned char	*as2;
	size_t				i;

	i = 0;
	as1 = (const unsigned char *)s1;
	as2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (as1[i] != as2[i])
			return (as1[i] - as2[i]);
		i++;
	}
	return (0);
}
