/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:31:48 by dmarquez          #+#    #+#             */
/*   Updated: 2021/08/30 10:43:18 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(unsigned	int nbr)
{
	int	len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nbr;
	int		len;

	len = ft_nbr_len(n);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (n != 0)
	{
		nbr[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (nbr);
}

int	ft_put_unsig(va_list	args)
{
	int		printed;
	int		n;
	char	*nbr;

	printed = 0;
	n = va_arg(args, unsigned int);
	if (n == 0)
		printed += write(1, "0", 1);
	else
	{
		nbr = ft_uitoa(n);
		printed += ft_putstr(nbr);
		free(nbr);
	}
	return (printed);
}
