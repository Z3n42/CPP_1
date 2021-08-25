/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:52:17 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/10 17:06:09 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_sharp_zero(char *hex, t_flags flags)
{
	char	*zero;
	int		i;
	int		l;

	if (flags.zero || flags.prec >= 0)
	{
		if (flags.prec > flags.zero)
			flags.zero = flags.prec;
		else
			flags.zero = flags.width - 2;
		l = flags.zero + 1 - ft_strlen(hex);
		if (l > 0)
		{
			i = -1;
			zero = malloc (l);
			if (!zero)
				return (0);
			while (++i < (l - 1))
				zero[i] = '0';
			zero[i] = 0;
			hex = ft_strjoin(zero, hex);
			free (zero);
		}
	}
	return (hex);
}

char	*ft_alloc_sharp(unsigned int n, t_flags flags)
{
	char	*pre;
	char	*hex;

	if (flags.type == 'x' && flags.sharp && n != 0)
	{
		hex = ft_alloc_hex(n);
		hex = ft_sharp_zero(hex, flags);
		pre = ft_strjoin("0x", hex);
		free(hex);
	}
	else if (flags.type == 'X' && flags.sharp && n != 0)
	{
		hex = ft_alloc_upperx(n);
		hex = ft_sharp_zero(hex, flags);
		pre = ft_strjoin("0X", hex);
		free(hex);
	}
	else
	{
		if (flags.type == 'x')
			pre = ft_alloc_hex(n);
		else
			pre = ft_alloc_upperx(n);
	}
	return (pre);
}

char	*ft_get_arg(va_list args, t_flags flags, char *fl)
{
	char	*arg;
	char	type;

	type = flags.type;
	if (type == 'd' || type == 'i')
		arg = ft_itoa(va_arg(args, int));
	if (type == 'u')
		arg = ft_itoa_u(va_arg(args, unsigned int));
	if (type == 's')
		arg = ft_strdup(va_arg(args, char *));
	if (type == '%')
		arg = ft_strdup("%");
	if (type == 'c')
		arg = ft_alloc_char(va_arg(args, int));
	if (type == 'x')
		arg = ft_alloc_sharp(va_arg(args, unsigned int), flags);
	if (type == 'X')
		arg = ft_alloc_sharp(va_arg(args, unsigned int), flags);
	if (type == 'p')
		arg = ft_alloc_ptr(va_arg(args, uintptr_t));
	if (type == 'z')
		arg = ft_alloc_char(fl[ft_strlen(fl) - 1]);
	return (arg);
}

int	ft_handle_percent(va_list args, char *str)
{
	int		length;
	char	*fl;
	char	*arg;
	t_flags	flags;

	length = 0;
	fl = ft_flags_info(str);
	flags = ft_init_flags();
	flags = ft_handle_flags(fl, flags);
	arg = ft_get_arg(args, flags, fl);
	if (flags.type != 'n')
		length += ft_print_arg(arg, fl);
	else
		length -= ft_strlen(fl) + 1;
	ft_clean(fl, arg);
	return (length);
}

int	ft_printf(const char *cpy, ...)
{
	va_list	args;
	int		i;
	int		length;
	char	*str;

	i = -1;
	length = 0;
	str = ft_strdup(cpy);
	va_start(args, cpy);
	while (str[++i] != 0)
	{
		if (str[i] == '%')
		{
			length += ft_handle_percent(args, &str[++i]);
			while (!ft_check_type(str[i]))
				i++;
		}
		else
			ft_putchar(str[i]);
	}
	va_end(args);
	i = ft_strlen(cpy) + length;
	free(str);
	return (i);
}
