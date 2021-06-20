/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmpmain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:56:37 by ingonzal          #+#    #+#             */
/*   Updated: 2021/06/07 20:47:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  <stdio.h>
#include "libft.h"

int	main(void)
{
	char			s1[6] = "Adioss";
	char			s2[6] = "Holaaa";
	int				comp;
	size_t			n;

	n = 4;
	comp = ft_strncmp(s1, s2, n);
	printf("comprobación: %d\n", comp);
}
