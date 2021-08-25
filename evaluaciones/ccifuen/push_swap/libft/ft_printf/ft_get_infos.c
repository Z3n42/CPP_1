/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:54:02 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:06:09 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_count_hex(uintptr_t n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

char	*ft_flags_info(char *str)
{
	int		i;
	char	*fl;

	i = 0;
	while (!ft_check_type(str[i]))
		i++;
	fl = malloc((i + 2) * sizeof(char));
	if (!fl)
		return (0);
	i = 0;
	while (!ft_check_type(str[i]))
	{
		fl[i] = str[i];
		i++;
	}
	fl[i] = str[i];
	i++;
	fl[i] = 0;
	return (fl);
}

char	ft_check_type(char c)
{
	char	*flags;
	int		i;
	char	r;

	if (!c)
		return ('n');
	flags = ft_strdup("cspdiuxX%");
	if (!flags)
		return (0);
	i = -1;
	while (flags[++i])
	{
		if (flags[i] == c)
		{
			r = flags[i];
			free(flags);
			return (r);
		}
	}
	if (ft_isalpha(c))
		return ('z');
	free(flags);
	return (0);
}
