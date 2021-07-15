/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel-por <adel-por@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 21:06:45 by adel-por          #+#    #+#             */
/*   Updated: 2021/06/30 20:53:02 by adel-por         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int	c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}

/*int	main(void)
{
	char	c;

	c = 'M';
	ft_tolower(c);
	printf("%c", ft_tolower(c));
	return (0);
}*/
