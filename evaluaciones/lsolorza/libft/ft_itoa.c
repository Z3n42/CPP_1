/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsolorza <lsolorza@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:15:28 by lsolorza          #+#    #+#             */
/*   Updated: 2021/06/22 18:15:37 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	abs_value(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;

	len = get_len(n);
	number = malloc(sizeof(char) * (len + 1));
	if (number == NULL)
		return (NULL);
	number[len] = '\0';
	if (n < 0)
		number[0] = '-';
	else if (n == 0)
		number[0] = '0';
	while (n != 0)
	{
		--len;
		number[len] = abs_value(n % 10) + '0';
		n = n / 10;
	}
	return (number);
}
