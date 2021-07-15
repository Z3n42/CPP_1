/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 20:36:54 by adel-por          #+#    #+#             */
/*   Updated: 2021/06/30 11:42:37 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*spr;

	i = 0;
	str = (unsigned char *)s1;
	spr = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((str[i] != '\0' || spr[i] != '\0') && (i < n))
	{
		if (str[i] != spr[i])
		{
			return (str[i] - spr[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[12];
	char	s2[12];

	strcpy(s1, "Comprobamos");
	strcpy(s2, "Conprobamos");
	printf("%d \n", ft_strncmp(s1, s2, 5));
}*/
