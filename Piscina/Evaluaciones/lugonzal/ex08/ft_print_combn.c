/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:28:04 by lugonzal          #+#    #+#             */
/*   Updated: 2021/04/27 10:30:58 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	a)
{
	write(1, &a, 1);
}

void	ft_print_combn(int n)
{
	int	i;
	int c;

	i=0;
	if(n > 0)
	{												
		while(){
		c=i+1;
		ft_putchar(i+'0');
		i++;	
		ft_putchar(i+'0');
		write(1, ", ", 2);
		c++;			
		}
	ft_print_combn(--n);		
	}
}	
int	main(void)
{
	int	n;

	n=	4;
	ft_print_combn(n);
}
