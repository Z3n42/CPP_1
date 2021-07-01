/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:05:53 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:06:03 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	while (*big && n >= ft_strlen(little))
	{	
		if (ft_strncmp(big, little, ft_strlen(little)) == 0)
			return ((char *)(big));
		n--;
		big++;
	}
	return (NULL);
}
