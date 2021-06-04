/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iechevar <iechevar@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:25:30 by iechevar          #+#    #+#             */
/*   Updated: 2021/04/26 17:25:34 by iechevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compare (char *str, char *to_find)
{
	while (*str && *to_find)
	{
		if (*str != *to_find)
		{
			return (0);
		}
		to_find++;
		str++;
	}
	return (*to_find == 0);
}

char	*ft_strstr (char *str, char *to_find)
{
	if (to_find[0] == 0)
		return (str);
	else
	{
		while (*str)
		{
			if (*str == *to_find && ft_compare(str, to_find))
			{
				return (str);
			}
			str++;
		}
		return (0);
	}
}
