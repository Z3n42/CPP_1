/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:53:40 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/20 11:53:42 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_alloc_char(char c)
{
	char	*ptr;

	ptr = malloc(2);
	ptr[0] = c;
	ptr[1] = '\0';
	return (ptr);
}

char	*ft_alloc_upperx(uintptr_t n)
{
	char	*hex;
	int		temp;
	int		i;

	if (!n)
		return (ft_strdup("0"));
	i = ft_count_hex(n) - 1;
	hex = malloc((i + 2) * sizeof(char));
	ft_bzero(hex, i + 2);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
		{
			hex[i] = temp + 48;
			i--;
		}
		else
		{
			hex[i] = temp + 55;
			i--;
		}
		n = n / 16;
	}
	return (hex);
}

char	*ft_alloc_hex(uintptr_t n)
{
	char	*hex;
	int		temp;
	int		i;

	if (!n)
		return (ft_strdup("0"));
	i = ft_count_hex(n) - 1;
	hex = malloc((i + 2) * sizeof(char));
	ft_bzero(hex, i + 2);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
		{
			hex[i] = temp + 48;
			i--;
		}
		else
		{
			hex[i] = temp + 87;
			i--;
		}
		n = n / 16;
	}
	return (hex);
}

char	*ft_alloc_ptr(uintptr_t n)
{
	char	*pre;
	char	*hex;

	if (!n)
		hex = ft_strdup("0");
	else
		hex = ft_alloc_hex(n);
	pre = ft_strjoin("0x", hex);
	free(hex);
	return (pre);
}

void	ft_clean(char *fl, char *arg)
{
	free(fl);
	free(arg);
}
