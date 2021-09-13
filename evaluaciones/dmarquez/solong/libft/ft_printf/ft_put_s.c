/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:58:38 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/22 17:23:05 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_string(va_list	args)
{
	int		printed;
	char	*s;

	printed = 0;
	s = va_arg(args, char *);
	printed = ft_putstr(s);
	return (printed);
}
