/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:55:12 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:06:09 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_percent_zero(t_flags flags, char *arg)
{
	if (flags.type == '%' && flags.zero)
	{
		flags.zero = flags.width;
		ft_print_zeros(flags, arg);
	}
}

t_flags	ft_print_arg_char(t_flags flags, char *arg)
{
	if (flags.type == 'c' || flags.type == '%' || flags.type == 'z')
	{
		ft_percent_zero(flags, arg);
		if (flags.prec > -1)
			arg[flags.prec] = 0;
		if (!flags.minus && !flags.zero)
			ft_print_width(flags, arg);
		if (!arg[0] && flags.type == 'c')
		{
			if (!flags.width)
				flags.width++;
			ft_putchar('\0');
		}
		else
			ft_putstr(arg);
		if (flags.minus)
			ft_print_width(flags, arg);
	}
	return (flags);
}

t_flags	ft_print_arg_str(t_flags flags, char *arg)
{
	if (flags.type == 's' || flags.type == 'p')
	{
		if (flags.prec == -2)
			flags.prec = 0;
		if (flags.prec > ft_strlen(arg))
			flags.prec = ft_strlen(arg);
		if (flags.prec > -1)
			arg[flags.prec] = 0;
		if (!flags.minus && !flags.zero)
			ft_print_width(flags, arg);
		if (!arg[0] && flags.type == 'c')
		{
			if (!flags.width)
				flags.width++;
			ft_putchar('\0');
		}
		else
			ft_putstr(arg);
		if (flags.minus)
			ft_print_width(flags, arg);
	}
	return (flags);
}

t_flags	ft_print_num(char *arg, t_flags flags)
{
	if (ft_all_digits(arg))
		if (ft_atoi(arg) == 0 && (flags.prec == -2 || flags.prec == 0))
			arg[0] = 0;
	if (flags.prec >= 0)
		flags = ft_num_prec(arg, flags);
	else if (flags.zero)
		flags = ft_num_zero(arg, flags);
	else if (!flags.minus)
		ft_print_width(flags, arg);
	if ((flags.plus && !flags.zero && ft_atoi(arg) >= 0 )
		&& (flags.num == 1 && flags.prec < 0))
		ft_putchar('+');
	if (!flags.plus && flags.space && flags.num == 1
		&& (ft_strlen(arg) >= flags.width || flags.minus) && flags.prec < 0)
		ft_putchar(' ');
	ft_putstr(arg);
	if (flags.minus)
		ft_print_width(flags, arg);
	if (flags.num && flags.prec != -1)
		flags.width += (flags.zero - ft_strlen(arg));
	if (flags.plus && flags.minus && flags.prec < 0)
		flags.width++;
	return (flags);
}
