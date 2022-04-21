/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:00:06 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:08:26 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s1) + 1;
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	else
		ft_memcpy (dst, s1, len);
	return (dst);
}

/* int	main(void)
{
	char *s1 = "HOLA";
	printf("%s\n", strdup(s1));
	printf("%s\n", ft_strdup(s1));
	return (0);
}
 */