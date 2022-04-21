/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:59:22 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:07:47 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (d < s && (dst || src))
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}	

/* int	main(void)
{
	char	dest[20] = "pasapasapasapasa";
	char	src[20] = "Que pasa";
	char	*ret;
	char	*ret2;

	ret = ft_memmove(dest, src, 3);
	printf("%s\n", ret);
	ret2 = memmove(dest, src, 3);
	printf("%s\n", ret2);
	return (0);
}
 */