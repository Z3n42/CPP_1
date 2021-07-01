/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivillaso <ivillaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:11:08 by ivillaso          #+#    #+#             */
/*   Updated: 2021/06/11 11:11:09 by ivillaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	x;
	char			*aux;

	x = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	aux = (char *)malloc(sizeof(char) * (len + 1));
	if (aux == NULL)
		return (NULL);
	while (s[x])
	{
		aux[x] = f(x, s[x]);
		x++;
	}
	aux[x] = '\0';
	return (aux);
}
