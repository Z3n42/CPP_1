/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:33:32 by iestevez          #+#    #+#             */
/*   Updated: 2021/04/22 11:33:35 by iestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
voidmft_print_reverse_alphabet (void)
{
	char	ultima;

	ultima = 'z';
	while (ultima >='a')
	{
		write (1, &ultima, 1);
		ultima--;
	}
	write (1, "\n", 1);
}
