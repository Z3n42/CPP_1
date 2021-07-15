/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 15:46:08 by mvillega          #+#    #+#             */
/*   Updated: 2021/05/28 17:50:49 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The bzero() function erases the data in the n bytes of the memory */
/* starting at the location pointed to by s, by writing zeros  */
/* (bytes containing '\0') to that area. tested: works great */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*suc;

	i = 0;
	suc = (unsigned char *) s;
	while (i < n)
	{
		suc[i] = 0;
		i++;
	}
	s = suc;
}
