/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:36:04 by adel-por          #+#    #+#             */
/*   Updated: 2021/06/30 11:17:27 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const	void	*s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((char *)s)[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

/*int	main(void)
{
	char	kad[]= "kadencita";
	printf("%s", ft_memchr(kad, 'e', 8));
}*/