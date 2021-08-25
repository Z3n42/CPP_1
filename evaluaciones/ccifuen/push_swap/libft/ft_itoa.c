/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:43:32 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:29:36 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_fill_m(char *ptr, int n, int a)
{
	int	k;

	k = n;
	if (k < 0)
	{
		k = k * -1;
		a++;
	}
	ptr[a] = 0;
	a--;
	while (k >= 10)
	{
		ptr[a] = (k % 10) + '0';
		k = k / 10;
		a--;
	}
	ptr[a] = k + '0';
}

char	*ft_allocate(int n, int a)
{
	char	*ptr;

	if (n < 0)
		ptr = malloc(a + 2);
	else
		ptr = malloc(a + 1);
	if (!ptr)
		return (0);
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		a;
	int		k;

	a = 1;
	k = n;
	if (k < 0)
		k = k * -1;
	while (k >= 10)
	{
		k = k / 10;
		a++;
	}
	if (n == -2147483648)
	{
		ptr = ft_strdup("-2147483648");
		return (ptr);
	}
	ptr = ft_allocate(n, a);
	if (!ptr)
		return (0);
	ft_fill_m(ptr, n, a);
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
