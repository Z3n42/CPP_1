/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpymain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:27:11 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/03 21:32:32 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	size_t		n;
	const char	src[] = "";
	char		dst[] = "";
	const char  src_[] = "";
    char        dst_[] = "";

	n = 3;
	printf("No cambiado: %s\n", dst);
	ft_memcpy(dst, src, n);
	printf("Cambiado: %s\n", dst);
	printf("Original No cambiado: %s\n", dst_);
    memcpy(dst_, src_, n);
    printf("Original Cambiado: %s\n", dst_);
}
