/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iestevez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:34:53 by iestevez          #+#    #+#             */
/*   Updated: 2021/04/23 12:14:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char hundreds, char tens, char units)

{		
	if (hundreds == '7')
	{
		write (1, &hundreds, 1);
		write (1, &tens, 1);
		write (1, &units, 1);
		write (1, " ", 1);
	}
	else
	{
		write (1, &hundreds, 1);
		write (1, &tens, 1);
		write (1, &units, 1);
		write (1, ", ", 1);
	}
}

void	ft_print_comb (void)
{
	char	hundreds;
	char	tens;
	char	units;
	{
		hundreds = '0';
		while (hundreds <= '7')
		}
		{			
			tens = hundreds + 1;
			while (tens <= '8')
			{					
				units = tens + 1;
				while (units <= '9')
				{
					ft_putchar(hundreds, tens, units);
					units++;
				}	
				tens ++;
			}	
			hundreds++;
		}		
		write (1, "\n", 1);
	}
}

void	ft_print_comb	(void);

int	main (void)
{
	ft_print_comb ();
}
