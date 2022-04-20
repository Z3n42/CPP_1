/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:59:48 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/16 14:39:03 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blacklist.hpp"

Contact::Contact(void){
	return;
}

Contact::~Contact(void){
	return;
}

static int	ft_integer(const char *str)
{
	int	integer;

	integer = 0;
	while (*str > 47 && *str < 58)
	{
		integer = (integer * 10) + (*str - '0');
		str++;
	}
	return (integer);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	plus;
	int	integer;

	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	minus = 0;
	plus = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus++;
		plus++;
		str++;
	}
	if (minus > 1 || plus > 1)
		return (0);
	integer = ft_integer(str);
	if ((minus % 2) != 0)
		integer = integer * (-1);
	return (integer);
}


