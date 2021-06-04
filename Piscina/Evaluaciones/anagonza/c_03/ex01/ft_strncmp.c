/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:01:29 by anagonza          #+#    #+#             */
/*   Updated: 2021/04/30 08:31:44 by anagonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (s1[count] != '\0' && s2[count] != '\0')
	{
		while (s1[count] == s2[count] && count < n -1)
		{
			count++;
			n--;
		}
	}
	return (s1[count] - s2[count]);
}
