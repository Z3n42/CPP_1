/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joiglesi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:49:15 by joiglesi          #+#    #+#             */
/*   Updated: 2021/04/29 10:46:33 by joiglesi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == 0)
		return (str);
	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i] == to_find[j] || to_find[j] == 0)
		{
			if (to_find[j] == 0)
				return (&str[i - j]);
			i++;
			j++;
		}
		if (j == 0)
			i++;
	}
	return (0x0);
}
