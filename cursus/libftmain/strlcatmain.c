/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcatmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:07:50 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/04 14:12:37 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	size_t	dstsize;
//	char	dst[100] = "Adiossi";
//	char	dst_[100] = "Adiossi";
	char	dst_[100] = "there is no stars in the sky";
	char	dst[] = "there is no stars in the sky";
	char 	src[] = "the cake is a lie !\0I'm hidden lol\r\n";
	char 	src_[] = "the cake is a lie !\0I'm hidden lol\r\n";
	
	dstsize = 20;
	printf("\nSize: %lu\n", dstsize);
	printf("\nFT : %lu\n", ft_strlcat(dst, src, dstsize));
	printf("Dest : %s\n", dst);
	printf("\nOriginal : %lu\n", strlcat(dst_, src_, dstsize));
	printf("Dest original : %s\n\n", dst_);
}
