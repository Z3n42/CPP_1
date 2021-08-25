/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:53:49 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:06:09 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.prec = -1;
	flags.zero = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.sharp = 0;
	flags.space = 0;
	flags.dot = 0;
	flags.num = 0;
	return (flags);
}

int	ft_get_width(char *str)
{
	int		i;
	char	*n;
	int		res;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i == 0)
		return (0);
	n = malloc((i + 1) * sizeof(char));
	i = -1;
	while (ft_isdigit(str[++i]))
		n[i] = str[i];
	n[i] = 0;
	res = ft_atoi(n);
	free(n);
	return (res);
}

t_flags	ft_bonus_flags(char c, t_flags flags)
{
	if (c == '+')
		flags.plus = 1;
	if (c == ' ')
		flags.space = 1;
	if (c == '#')
		flags.sharp = 1;
	if (c == '0')
		flags.zero = 1;
	if (c == '-')
		flags.minus = 1;
	return (flags);
}

t_flags	ft_handle_flags(char *fl, t_flags flags)
{
	int	i;

	i = 0;
	while (!ft_check_type(fl[i]))
		i++;
	flags.type = ft_check_type(fl[i]);
	i = -1;
	while (!ft_check_type(fl[++i]))
	{
		flags = ft_bonus_flags(fl[i], flags);
		while (ft_isdigit(fl[i]) && fl[i] != '0')
		{
			if (!flags.width)
				flags.width = ft_get_width(&fl[i]);
			i++;
		}
		if (fl[i] == '.')
		{
			flags.prec = -2;
			while (ft_isdigit(fl[++i]))
				if (flags.prec < 0)
					flags.prec = ft_get_width(&fl[i]);
		}
	}
	return (flags);
}
