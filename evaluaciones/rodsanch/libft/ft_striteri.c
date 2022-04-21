/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:13:02 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:08:32 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/* void	my_func(unsigned int i, char *str)
{
printf("My inner function: index = %d and the string is %s\n", i, str);
}

int	main()
{
    char	str[10] = "Hello.";
    printf("The result is %s\n", str);
    ft_striteri(str, my_func);
 	printf("The result is %s\n", str);
 	return 0;
}
 */