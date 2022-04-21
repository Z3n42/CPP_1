/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:09:15 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:09:02 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && (i < (n - 1)) && (s1[i] != '\0'))
			i++;
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

/* int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = "Rodri";
	str2 = "Rodrigo";
	printf("%d\n", ft_strncmp(str1, str2, 5));
	printf("%d\n", ft_strncmp(str1, str2, 8));
}
 */