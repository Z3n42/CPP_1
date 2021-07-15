/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 19:04:07 by adel-por          #+#    #+#             */
/*   Updated: 2021/06/30 12:57:29 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;
	size_t	j;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	j = dlen;
	if (dstsize == 0)
		return (slen);
	if (dstsize < dlen)
		return (dstsize + slen);
	else
	{
		while (src[i] != '\0' && (dlen + i) < dstsize)
			dst[j++] = src[i++];
		if ((dlen + i) == dstsize && dlen < dstsize)
			dst[j - 1] = '\0';
		else
			dst[j] = '\0';
		return (dlen + slen);
	}
}

/*int	main(void)
{
	char	kad[8] = "Firstone";
	char	kod[5] = "Sader";
	printf("%lu", ft_strlcat(kad, kod, 9));
//	printf("%lu", strlcat(kad, kod, 10));
	return (0);
}*/