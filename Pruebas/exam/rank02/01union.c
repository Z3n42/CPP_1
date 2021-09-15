/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01union.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:57:22 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/15 14:27:10 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int t;

	i = 0;
	j = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			while (argv[1][j] && j <= i)
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
						if (argv[1][k] == argv[2][i])
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
