/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsmith <jsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:37:16 by jsmith            #+#    #+#             */
/*   Updated: 2021/06/03 19:54:02 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	r;

	a = 0;
	b = 0;
	r = 0;
	while (dest[a] != '\0')
		a++;
	while (src[r] != '\0')
		r++;
	if (size < a)
		r = r + size;
	else
		r = r + a;
	while (src[b] != '\0' && a + 1 < size)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (r);
}

int main(void)
{
    size_t  dstsize;
    char    dst_[10] = "Adiossi";
    char    dst[10] = "Adiossi";
    char    src_[] = "Holaaa";
    char    src[] = "Holaaa";

    dstsize = 1;
    printf("\nSize: %lu\n", dstsize);
    printf("\nFT : %u\n", ft_strlcat(dst, src, dstsize));
    printf("Dest : %s\n", dst);
    printf("\nOriginal : %lu\n", strlcat(dst_, src_, dstsize));
    printf("Dest original : %s\n\n", dst_);
}
