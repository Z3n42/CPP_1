/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:18:27 by adel-por          #+#    #+#             */
/*   Updated: 2021/07/05 12:45:58 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*str;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		str[i] = s2[k];
		k++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
