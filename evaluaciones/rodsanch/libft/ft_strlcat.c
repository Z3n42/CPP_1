/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:13:52 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:08:42 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (dst[len] && len < dstsize)
		len++;
	i = len;
	while (src[len - i] && len + 1 < dstsize)
	{
		dst[len] = src[len - i];
		len++;
	}
	if (i < dstsize)
		dst[len] = '\0';
	return (i + ft_strlen(src));
}

/* int main()
{
	char dst[] = "que hhhhggggg";
	char src[] = "pas";
	size_t dstsize = 2;

	printf("%lu\n", ft_strlcat(dst, src, dstsize));
	printf("%lu\n", strlcat(dst, src, dstsize));
	ft_strlcat(dst, src, dstsize);
	printf("%s\n", dst);
	strlcat(dst, src, dstsize);
	printf("%s\n", dst);
}
 */