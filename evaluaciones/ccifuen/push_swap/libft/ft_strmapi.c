/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:54:52 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ptr;

	if (!s)
		return (0);
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	i = -1;
	while (s[++i])
		ptr[i] = f(i, s[i]);
	ptr[i] = 0;
	return (ptr);
}
