/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpymain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:34:37 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/05 14:10:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

int	main(void)
{
	size_t		n;
	char		c;
   	const char 	src[] = "test basic du memccpy !";
    char		dst[] = "";
    const char	src_[] = "test basic du memccpy !";
    char		dst_[] = "";

	n = 21;
	c = 'm';
	printf("\nSize: %lu\n", n);
	printf("Char: %c\n\n", c);
	printf("No cambiado: %s\n", dst);
	ft_memccpy(dst, src, c, n);
	printf("Cambiado: %s\n\n", dst);
	printf("Original No cambiado: %s\n", dst_);
	memccpy(dst_, src_, c, n);
	printf("Original Cambiado: %s\n\n", dst_);	
}
