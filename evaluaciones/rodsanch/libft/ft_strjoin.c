/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodsanch <rodsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:59:16 by rodsanch          #+#    #+#             */
/*   Updated: 2022/04/19 17:08:37 by rodsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*double_str;
	int		i;
	int		j;

	double_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 == NULL || s2 == NULL || double_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		double_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		double_str[i] = s2[j];
		i++;
		j++;
	}
	double_str[i] = '\0';
	return (double_str);
}

/* int	main(void)
{
	printf("%s\n", ft_strjoin("Q ", "pasa"));
	return (0);
}
 */