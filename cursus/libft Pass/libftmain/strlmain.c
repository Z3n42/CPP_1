/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:24:10 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/01 14:30:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"
#include "string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

int main(void)
{
	size_t		dstsize;
	char		dst[] = "Adioooosito";
	const char	src[] = "Hola";
	size_t		i;
	size_t		k;

	dstsize = 5;
	printf("Src in: %s", src);	
	printf("\n");
	printf("Dst in: %s", dst);	
	printf("\n");
	printf("Dstsize: %zu", dstsize);	
	printf("\n");
	i = ft_strlcpy(dst, src, dstsize);
	printf("Return: %zu", i);
	printf("\n");
	k = strlcpy(dst, src, dstsize);
	printf("Original: %zu", k);
	printf("\n");
}
