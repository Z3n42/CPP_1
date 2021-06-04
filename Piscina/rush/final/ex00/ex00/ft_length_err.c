/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 18:48:33 by ingonzal          #+#    #+#             */
/*   Updated: 2021/04/25 19:32:35 by lsolorza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_error.h"

int	ft_length_err(char *argv)
{
	int	length;

	length = 0;
	while (argv[length] != '\0')
	{
		length++;
	}
	if (length != 31)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
