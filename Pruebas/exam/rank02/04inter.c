/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04inter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:16:30 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/22 16:48:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int	j;
	int	k;
	int	t;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[1][j])
			{
				if (argv[1][i] == argv[1][j] && i != j)
					break;
				else if (argv[1][i] == argv[1][j] && i == j)
				{
					k = 0;
					t = 0;
					while (argv[2][k])
					{
						if (argv[2][k] == argv[1][i])
							t = 1;
						k++;
					}	
					if (t == 1)
						write(1, &argv[1][i], 1);
				}
				j++;
			}
			j = 0;
			if(argv[1][i])
				i++;
		}
	}
	write(1, "\n", 1);
}
