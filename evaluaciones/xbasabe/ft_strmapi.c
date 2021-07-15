/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbasabe- <xbasabe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 13:47:22 by xbasabe-          #+#    #+#             */
/*   Updated: 2021/06/10 12:28:05 by xbasabe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*str;
	size_t		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
