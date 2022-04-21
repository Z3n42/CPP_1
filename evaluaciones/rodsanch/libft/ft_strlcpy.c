/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:46:22 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:08:48 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	x;

	count = 0;
	x = 0;
	while (src[count] != '\0')
		count++;
	if (dstsize != 0)
	{
		while (src[x] != '\0' && x < (dstsize - 1))
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (count);
}

/* int main (void)
{
	char dst[] = "pasa";
	const char src[] = "qué pasa";
	size_t dstsize = 5;

	printf("%lu\n", ft_strlcpy(dst, src, dstsize));
	printf("%lu\n", strlcpy(dst, src, dstsize));
	printf("%s\n", dst);
	ft_strlcpy(dst, src, dstsize);
	printf("%s\n", dst);
	strlcpy(dst, src, dstsize);
	printf("%s\n", dst);
}
 */