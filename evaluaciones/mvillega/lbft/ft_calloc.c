/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillega <mvillega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:31:39 by mvillega          #+#    #+#             */
/*   Updated: 2021/06/15 15:03:43 by mvillega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*rtrn;

	rtrn = malloc(count * size);
	if (!rtrn)
		return (NULL);
	ft_bzero(rtrn, count * size);
	return (rtrn);
}
