/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iechevar <iechevar@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:25:30 by iechevar          #+#    #+#             */
/*   Updated: 2021/04/26 17:25:34 by iechevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comparative1(char *s1, char *s2, int i)
{
	if (s1[i] == 0 && s2[i] != 0 )
		return (-1);
	else if (s2[i] == 0 && s1[i] != 0)
		return (1);
	else
		return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (s1[i] != 0 && s2[i] != 0 && result == 0)
	{
		if (s1[i] > s2[i])
			result = 1;
		else if (s1[i] < s2[i])
			result = -1;
		else
			result = 0;
		i++;
	}
	if (result != 0)
		return (result);
	else
	{
		return (comparative1(s1, s2, i));
	}
}
