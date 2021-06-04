/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sveloso- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:36:36 by sveloso-          #+#    #+#             */
/*   Updated: 2021/04/30 10:43:59 by sveloso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		pos;
	char	a;

	pos = 1;
	if (str[0] >= 97 && str[0] <= 122)
		str[0] = str[0] - 32;
	while (str[pos] != '\0')
	{
		a = str[pos - 1];
		if (!((a >= 97 && a <= 122) || (a >= 65 && a <= 90)))
		{
			if (str[pos] >= 97 && str[pos] <= 122)
				if (!(str[pos - 1] >= '0' && str[pos - 1] <= '9'))
					str[pos] = str[pos] - 32;
		}
		if (str[pos] >= 65 && str[pos] <= 90)
			if (str[pos - 1] >= '0' && str[pos - 1] <= '9')
				str[pos] = str[pos] + 32;
		if ((a >= 65 && a <= 90) && (str[pos] >= 65 && str[pos] <= 90))
			str[pos] = str[pos] + 32;
		if ((a >= 97 && a <= 122) && (str[pos] >= 65 && str[pos] <= 90))
			str[pos] = str[pos] + 32;
		pos++;
	}
	return (str);
}
