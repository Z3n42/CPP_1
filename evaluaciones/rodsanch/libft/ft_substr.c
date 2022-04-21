/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:39:48 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/21 12:49:49 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len <= 0)
	{
		substr = (char *)malloc(1);
		substr[0] = '\0';
		return (substr);
	}	
	if (len > ft_strlen(s) && start < ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = malloc(sizeof(*s) * len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

 /* int	main(void) */
/* { */
	/* char *str = "tripouille"; */
	/* size_t size = 10; */
	/* printf("%s\n", ft_substr(str, 5, size)); */
	/* return (0); */
/* } */
