/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:03:03 by anagonza          #+#    #+#             */
/*   Updated: 2021/04/29 18:05:51 by anagonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		count;
	int		pos;

	count = 0;
	pos = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[count] != '\0')
	{
		while (to_find[pos] == str[count + pos])
		{
			if (to_find[pos + count] == '\0')
				return (str + count);
			pos++;
		}
		count++;
	}
	return (0);
}
