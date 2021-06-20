/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmovemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 17:37:10 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/05 18:47:08 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	size_t		len;
   	const char 	src[] = "test basic" /*du memccpy !"*/;
    char		dst[] = "123456789123456789";
    const char	src_[] = "test basic" /*du memccpy !"*/;
    char		dst_[] = "123456789123456789";

	len = 4;
	printf("\nSize: %lu\n", len);
	printf("No cambiado: %s\n", dst);
	ft_memmove(dst, src, len);
	printf("Cambiado: %s\n\n", dst);
	printf("Original No cambiado: %s\n", dst_);
	memmove(dst_, src_, len);
	printf("Original Cambiado: %s\n\n", dst_);	
}
