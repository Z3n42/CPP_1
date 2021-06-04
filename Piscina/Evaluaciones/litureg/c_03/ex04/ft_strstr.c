/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liturreg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 18:31:42 by liturreg          #+#    #+#             */
/*   Updated: 2021/05/03 14:38:43 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	change;

	if (*to_find == 0)
		return (str);
	count = 0;
	while (str[i] != '\0')
	{
		change = 0;
		while (to_find[change] == str[i + change])
		{
			if (to_find[change + 1] == '\0')
				return (str + i);
			change++;
		}
		i++;
	}
	return (0);
}

#include <stdio.h>

char *ft_strstr(char *str, char *to_find);

int main(void)
{

	char str[] = "AdiossHolar";
	char to_find[] = "dios";

	printf("%s\n", ft_strstr(str, to_find));
}
