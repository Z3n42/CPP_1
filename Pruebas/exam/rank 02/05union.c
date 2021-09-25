/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05union.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:50:16 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/22 18:26:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int t;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i])
		{
			while (argv[1][j])
			{
				if (argv[1][i] == argv[1][j] && i != j)
					break;
				else if (argv[1][i] == argv[1][j] && i == j)
					write(1, &argv[1][i], 1);
				j++;
			}
			j = 0;
			if (argv[1][i])
				i++;
		}
		i = 0;
		j = 0;
		while (argv[2][i])
		{
			while (argv[2][j])
			{
				if (argv[2][i] == argv[2][j] && i != j)
					break;
				else if (argv[2][i] == argv[2][j] && i == j)
				{
					k = 0;
					t = 0;
					while (argv[1][k])
					{
						if (argv[2][i] == argv[1][k])
							t = 1;
						k++;
					}
					if (t == 0)
						write(1, &argv[2][i], 1);
				}
				j++;
			}
			j = 0;
			if (argv[2][i])
				i++;
		}
	}
	write(1, "\n", 1);
}
