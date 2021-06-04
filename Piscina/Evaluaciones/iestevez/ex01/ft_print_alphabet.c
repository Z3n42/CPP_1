/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:32:54 by iestevez          #+#    #+#             */
/*   Updated: 2021/04/23 12:08:50 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_print_alphabet (void)
{
	char	primera;

	primera = 'a';
	while (primera <= 'z')
	{
		write (1, &primera, 1);
		primera++;
	}
	write (1, "\n", 1);
}

void	ft_print_alphabet(void);

int 	main (void)
{
	ft_print_alphabet ();
}
