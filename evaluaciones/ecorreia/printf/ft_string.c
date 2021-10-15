/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecorreia <ecorreia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:26:11 by ecorreia          #+#    #+#             */
/*   Updated: 2021/10/11 17:44:19 by ecorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(va_list vars)
{
	int		i;
	int		size;
	char	*c;

	size = 0;
	i = 0;
	c = va_arg(vars, char *);
	if (c == NULL)
		return (write(1, "(null)", 6));
	while (c[i] != '\0')
	{
		size += write (1, &c[i], 1);
		i++;
	}
	return (size);
}
