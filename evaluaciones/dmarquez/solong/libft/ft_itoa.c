/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:01:57 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:52:27 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	ft_positoa(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

static int	ft_len(int n)
{
	int		nbrlen;

	if (n < 0)
		nbrlen = ft_nbrlen(n);
	if (n > 0)
		nbrlen = ft_nbrlen(n) - 1;
	return (nbrlen);
}

static char	*ft_mallocitoa(int len, int n)
{
	char	*str;
	int		aux;

	aux = 0;
	if (n < 0)
		aux = 1;
	str = (char *)malloc(len + 1 + aux);
	if (!str)
		return (NULL);
	if (aux == 1)
	{
		str[0] = '-';
		str[len + 1] = '\0';
	}
	else
		str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbrlen;

	nbrlen = ft_len(n);
	if (n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	if (n != 0)
	{
		str = ft_mallocitoa(ft_nbrlen(n), n);
		if (!str)
			return (NULL);
		while (n != 0)
		{
			str[nbrlen--] = (ft_positoa(n % 10) + 48);
			n = n / 10;
		}
	}
	return (str);
}
