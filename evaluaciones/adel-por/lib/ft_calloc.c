/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:50:01 by adel-por          #+#    #+#             */
/*   Updated: 2021/07/01 19:07:10 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t	size)
{
	size_t		i;
	void		*str;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	i = 0;
	while (i < size * count)
	{	
		((unsigned char *)str)[i] = 0;
		i++;
	}	
	return (str);
}

/*int	main(void)
{
	char	kad[10] = "aitoraitor";
	printf("%s", ft_calloc(10, 10));
	printf("%s", calloc(10, 10));
}*/
