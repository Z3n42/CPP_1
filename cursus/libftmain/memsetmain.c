/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memsetmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 18:49:15 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/01 11:43:08 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len);

int	main(void)
{
	size_t	len;
	char	c;
	char	b[] = "Aupa ahi lukas";

	c = '$';
	len = 6;
	printf("No Cambiado: %s", b);
	ft_memset(b, c, len);
	printf("Cambiado: %s", b);
}
