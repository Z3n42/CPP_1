/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strincpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:41:42 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/05/03 12:40:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' && j == 0)
		{
			str[i] = str[i] - 32;
			i++;
		}
		while ((str[i] > 96 && str[i] < 123) || (str[i] > 64 && str[i] < 91)
			|| (str[i] > 47 && str[i] < 58))
		{
			if (str[i] >= 'A' && str[i] <= 'Z' && j != 0)
				str[i] = str[i] + 32;
			i++;
			j++;
		}
		i++;
		j = 0;
	}
	return (str);
}

#include <stdio.h>

char *ft_strcapitalize(char *str);

int main(void)
{
    char    str[] = "sa! lUT, coMMent t_U VAS ? ?42MOTS quARAnte-DEUX; cinquANTE+et+un";

    ft_strcapitalize(str);
    printf("%s", str);
}
