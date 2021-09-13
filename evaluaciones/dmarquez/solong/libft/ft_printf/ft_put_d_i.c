/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:06:48 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/22 20:20:25 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(va_list	args)
{
	int		printed;
	int		n;
	char	*nbr;

	printed = 0;
	n = va_arg(args, int);
	nbr = ft_itoa(n);
	printed = ft_putstr(nbr);
	free(nbr);
	return (printed);
}
