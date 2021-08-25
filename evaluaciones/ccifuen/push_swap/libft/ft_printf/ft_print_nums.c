/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:55:01 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:06:09 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flags	ft_check_print_num(t_flags flags, char *a)
{
	if (flags.width && !flags.zero && flags.prec == -1)
	{
		if (ft_atoi(a) < 0)
			flags.width++;
	}
	else if (flags.zero < ft_strlen(a) && flags.prec >= 0)
	{
		flags.width += flags.zero - ft_strlen(a);
		if (ft_atoi(a) < 0)
			flags.width++;
	}
	else if (flags.zero < ft_strlen(a))
	{
		flags.width++;
		flags.width += flags.zero - ft_strlen(a);
	}
	if (flags.minus && (a[0] == '0' && ft_atoi(a) != 0))
		flags.width--;
	if (ft_atoi(a) < 0)
		flags.width--;
	if (flags.type == 'u' && flags.prec >= 10 && flags.prec == ft_strlen(a))
		flags.width++;
	return (flags);
}

t_flags	ft_num_prec(char *arg, t_flags flags)
{
	flags.zero = flags.prec;
	if (!flags.plus && flags.space && flags.space
		&& (flags.width <= ft_strlen(arg) + flags.zero || flags.minus))
	{
		ft_putchar(' ');
	}
	flags.width -= (flags.zero - ft_strlen(arg));
	if (!flags.minus)
		ft_print_width(flags, arg);
	if (ft_atoi(arg) < 0 && flags.zero >= ft_strlen(arg) && flags.type != 'u')
	{
		arg[0] = '0';
		ft_putchar('-');
		flags.prec++;
	}
	if (flags.plus && ft_atoi(arg) >= 0)
		ft_putchar('+');
	ft_print_zeros(flags, arg);
	return (flags);
}

t_flags	ft_num_zero(char *arg, t_flags flags)
{
	flags.zero = flags.width;
	if (flags.minus)
		flags.zero = 0;
	if (ft_atoi(arg) < 0 && flags.zero > ft_strlen(arg) && flags.type != 'u')
	{
		arg[0] = '0';
		ft_putchar('-');
		flags.zero--;
	}
	if (flags.plus && flags.prec < 0 && ft_atoi(arg) >= 0)
	{
		if (!flags.minus)
			ft_putchar('+');
	}
	if (!flags.plus && flags.space)
	{
		flags.zero--;
		flags.space = 0;
		ft_putchar(' ');
	}
	ft_print_zeros(flags, arg);
	return (flags);
}

int	ft_all_digits(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

t_flags	ft_isnum(char *arg, t_flags flags)
{
	if (flags.type == 'd' || flags.type == 'i' || flags.type == 'u')
	{
		if (ft_atoi(arg) < 0)
		{
			flags.plus = 0;
			flags.space = 0;
		}
		flags.num = 1;
		flags = ft_print_num(arg, flags);
	}
	if (flags.type == 'x' || flags.type == 'X')
	{
		flags.num = 2;
		flags = ft_print_num(arg, flags);
	}
	return (flags);
}
