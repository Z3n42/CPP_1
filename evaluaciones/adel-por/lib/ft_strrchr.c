/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:35:31 by adel-por          #+#    #+#             */
/*   Updated: 2021/06/30 11:13:08 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		i;
	size_t	k;

	i = 0;
	k = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + k);
	while (k--)
	{
		if (*(s + k) == (char)c)
		{
			return ((char *)s + k);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char 	kad[] = "Firstarrray";
	printf("%s", ft_strrchr(kad, 'a'));
}*/