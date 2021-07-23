/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:03:01 by iibanez-          #+#    #+#             */
/*   Updated: 2021/06/07 19:48:05 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s3;
	const unsigned char	*s4;

	if (s1 == s2 || n == 0)
		return (0);
	s3 = (const unsigned char *) s1;
	s4 = (const unsigned char *) s2;
	while (n > 0)
	{
		if (*s3 != *s4)
			return (*s3 - *s4);
		s3++;
		s4++;
		n--;
	}
	return (0);
}
