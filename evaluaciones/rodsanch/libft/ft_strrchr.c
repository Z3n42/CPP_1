/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:18:13 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:09:13 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*end;

	i = ft_strlen(s);
	end = s;
	s = (s + i);
	while (*s != *end && (char)c != *s)
		s--;
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}

/* int	main()
{
	printf("%s\n", strrchr("Hola mundo aa", 'o'));
	printf("%s\n", ft_strrchr("Hola mundo aa", 'o'));
	return 0;
}
 */