/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:14:27 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:42:51 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const	char *str)
{
	int	pos;
	int	printed;

	printed = 0;
	pos = -1;
	while (str[++pos])
		printed += write(1, &str[pos], 1);
	return (printed);
}
