/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:08:41 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/21 10:12:02 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc (size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (pointer == NULL)
		return (NULL);
	ft_bzero(pointer, count * size);
	return (pointer);
}
