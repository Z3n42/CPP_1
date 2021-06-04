/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iechevar <iechevar@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:10:10 by iechevar          #+#    #+#             */
/*   Updated: 2021/04/27 18:10:25 by iechevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar (char c)
{
	write(1, & c, 1);
}

int	ft_strlen (char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_check (char *base)
{
	int	i;
	int	j;

	if (base[0] == 0 || base[1] == 0)
		return (0);
	i = 0;
	while (base[i] != 0)
	{
		if (!(base[i] >= 33) && base[i] <= 126)
			return (0);
		if (base[i] == '+' || base[j] == '-')
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base (int nbr, char *base)
{
	int	size;
	int	count;
	int	num[20];

	if (ft_check (base))
	{
		size = ft_strlen (base);
		if (nbr < 0)
		{
			nbr = nbr * -1;
			ft_putchar (45);
		}
		count = 0;
		while (nbr >= size)
		{
			num[count++] = base[nbr % size];
			nbr = nbr / size;
		}
		num[count++] = base[nbr];
		while (--count >= 0)
			ft_putchar (num[count]);
	}	
}
