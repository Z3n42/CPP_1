/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:11:22 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:11:30 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = malloc(size * nmemb);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, nmemb * size);
	return (str);
}
