/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 07:12:51 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/05/05 09:51:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	char	*aux;
	int		mult;
	int		i;

	mult = 1;
	i = 0;
	aux = str;
	while (*aux == ' ' || *aux == '\t' || *aux == '\r'
		|| *aux == '\f' || *aux == '\v' || *aux == '\n')
		aux++;
	while (*aux == '+' || *aux == '-')
	{
		if (*aux == '-')
			mult *= -1;
		aux++;
	}
	while (*aux >= '0' && *aux <= '9')
	{
		i *= 10;
		i += (*aux - '0');
		aux++;
	}
	return (i * mult);
}

#include <stdio.h>

int ft_atoi(char *str);

int main(void)
{
    char    *str;

    str = "   ---+--+1234ab567";
    printf("%d", ft_atoi(str));
}
