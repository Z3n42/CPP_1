/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanmicro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/03/17 20:39:00 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[], char **envp)
{
	int	fd[2];
	int	pid;
	int status;
	int i;
	int j;
	int	aux;
	int dir;

	pid = 0;
	pipe(fd);
	i = 1;
	j = i;
	while (i < argc)
	{
		while (argv[j] != NULL || j < argc)
		{
			if (argv[j] != NULL)
			{
				if (strcmp(argv[j], "cd") == 0)
				{
					j++;
					if (argc > 3 && j < (argc - 1))
					{
						if (argv[j + 1][0] != ';')
						{
							aux = j;
							while (argv[aux] && argv[aux][0] != ';')
								aux++;
							if ((aux - j) != 1)
							{
								printf("error: cd: bad arguments\n");
								j = aux;
								break;
							}
							j = aux;
						}
					}
					dir = chdir(argv[j]);
					if(dir == -1)
					{
						printf("error: cd: cannot change directory to path_to_change\n");
						exit(0);	
					}
				}
				else
				{
					pid = fork();
					if (pid == 0)
					{
						if (strcmp(argv[j], ";") == 0)
							exit(0);
						aux = j;
						while (argv[aux] && argv[aux][0] != ';')
							aux++;
						argv[aux] = NULL;
						if (strcmp(argv[j - 1], "cd") != 0)		
						{
							if (execve(argv[j], &argv[j], envp) == -1)
								printf("error: cannot execute executable_that_failed\n");
						}
						exit(0);
					}
					waitpid(0, &status, 0);
					/* if (status != 0) */
					/* 	return (0); */
				}
			}
			j++;
		}
		i = j;
	}
	return (0);
}
