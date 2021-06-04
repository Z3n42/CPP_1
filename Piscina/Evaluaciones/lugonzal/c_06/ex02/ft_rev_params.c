/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:45:44 by lugonzal          #+#    #+#             */
/*   Updated: 2021/05/06 16:00:22 by lugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rev_params(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		ft_putchar(argv[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	argc -= 1;
	while (0 < argc)
	{
		ft_rev_params(argv[argc]);
		--argc;
	}
}
