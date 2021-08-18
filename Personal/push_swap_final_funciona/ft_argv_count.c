/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argv_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:49:57 by ingonzal          #+#    #+#             */
/*   Updated: 2021/08/06 17:09:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_count(char const *s, char c)
{
	int	counter;
	int	pos;

	counter = 0;
	pos = 0;
	while (s[counter])
	{
		if (s[counter] == c && s[counter + 1] != c)
			pos++;
		counter++;
	}
	return (pos + 1);
}
