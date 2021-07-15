/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:45:51 by adel-por          #+#    #+#             */
/*   Updated: 2021/07/06 13:44:33 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*str;
	size_t	k;

	if (!set || !s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	k = ft_strlen(s1);
	while (k && ft_strchr(set, s1[k]))
		k--;
	str = ft_substr((char *)s1, 0, k + 1);
	return (str);
}

/*int	main(void)
{
	printf("%s", ft_strtrim("   hjhjhjh   ", " "));
	return (0);
}*/
