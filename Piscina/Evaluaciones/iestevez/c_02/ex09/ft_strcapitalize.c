/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:11:42 by iestevez          #+#    #+#             */
/*   Updated: 2021/05/03 19:55:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

char	*ft_strcapitalize (char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] = (str[i] + 32);
		i++;
	}
	if (str[0] > 96 && str[0] < 123)
		str[0] = (str[0] - 32);
	if (str[i] == 43 || str[i] == 45)
		str[i + 1] = (str[i + 1] - 32);
	if (str[i] == 32)
	{
		if ((str[i + 1] > 96) && (str[i + 1] < 123))
			str[i + 1] = (str[i + 1] - 32);
	}
	i++;
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
