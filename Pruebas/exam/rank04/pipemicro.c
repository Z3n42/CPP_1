/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipemicro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/03/23 17:57:26 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[], char **envp)
{
	int	fd[2][2];
	int	pid;
	int status;
	int j;
	int	aux;
	int dir;

	pid = 0;
	j = 0;
	while (j < 2)
	{
		aux = pipe(fd[j]);
		if (aux != 0)
		{
			printf("error: fatal\n");
			return (0);
		}
		j++;
	}
	j = 1;
	while (argv[j] || j < argc)
	{
		if (argv[j] != NULL && argv[j])
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
				if (strcmp(argv[j], ";") == 0 || strcmp(argv[j], "|") == 0)
					j++;
				pid = fork();
				if (pid == -1)
				{
					printf("error: fatal\n");
					return (0);
				}
				if (pid == 0)
				{
					/* if (strcmp(argv[j], ";") == 0) */
					/* 	exit(0); */
					aux = j;
					while (argv[aux] && argv[aux][0] != ';' && argv[aux][0] != '|')
						aux++;
					argv[aux] = NULL;
					if (execve(argv[j], &argv[j], envp) == -1)
						printf("error: cannot execute %s\n", argv[j]);
					exit(0);
				}
				waitpid(0, &status, 0);
				aux = j;
				while (argv[aux] && argv[aux][0] != ';' && argv[aux][0] != '|' && aux < (argc - 1))
					aux++;
				if ((aux - j) != 1)
					j = aux;
				if ((argv[aux + 1]) == NULL)
					return (0);
			}
			j++;
		}
	}
	return (0);
}
