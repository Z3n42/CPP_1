/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iibanez- <iibanez-@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:50:08 by iibanez-          #+#    #+#             */
/*   Updated: 2021/06/08 18:49:45 by iibanez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;

	s3 = (unsigned char *) s1;
	s4 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (*s3 != '\0' && n - 1 > 0)
	{
		if (*s3 != *s4)
			return (*s3 - *s4);
		s3++;
		s4++;
		n--;
	}
	return (*s3 - *s4);
}
