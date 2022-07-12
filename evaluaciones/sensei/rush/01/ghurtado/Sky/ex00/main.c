/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghurtado <ghurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:00:23 by ghurtado          #+#    #+#             */
/*   Updated: 2022/07/12 15:06:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_verify_args(int *nbrs, char *argv);

int	main(int argc, char **argv)
{
	int	nbrs[16];
	(void)argc; 

	if (ft_verify_args(nbrs, argv[1]))
	{
		write(1, "Error", 5);
	}
	return (0);
}
