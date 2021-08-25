/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:54:23 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:06:09 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_fill_m_u(char *ptr, unsigned int n, int a)
{
	unsigned int	k;

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

char	*ft_allocate_u(unsigned int n, int a)
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

char	*ft_itoa_u(unsigned int n)
{
	char			*ptr;
	int				a;
	unsigned int	k;

	a = 1;
	k = n;
	if (k < 0)
		k = k * -1;
	while (k >= 10)
	{
		k = k / 10;
		a++;
	}
	ptr = ft_allocate_u(n, a);
	if (!ptr)
		return (0);
	ft_fill_m_u(ptr, n, a);
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}
