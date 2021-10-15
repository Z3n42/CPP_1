/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:37:54 by ecorreia          #+#    #+#             */
/*   Updated: 2021/06/29 19:45:47 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned int	str;
	char			*ptr;

	str = nmemb * size;
	ptr = malloc(str);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, str);
	return (ptr);
}
