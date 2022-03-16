/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/03/16 21:49:21 by ingonzal         ###   ########.fr       */
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

	pipe(fd);
	i = 1;
	j = i;
	printf("XXXXXXXX ARGC Strcmp %i\n", argc);
	while (i < argc)
	{
		while (argv[j] != NULL || j < argc)
		{
			printf("1 - PRE Strcmp %i\n", j);
			if (argv[j] != NULL)
			{
				if (strcmp(argv[j], ";") == 0)
				{
					/* printf("2 - Strcmp %s\n", argv[j]); */
					j++;
					break;
				}
				pid = fork();
				if (pid == 0)
				{
					aux = j;
					while (argv[aux] && argv[aux][0] != ';')
						aux++;
					argv[aux] = NULL;
					if (strcmp(argv[j], "cd") == 0)
					{
						j++;
						/* printf("3 - %s\n", argv[j]); */
						dir = chdir(argv[j]);
						/* printf("4 - POST %i\n", dir); */
						exit(1);
					}
					else
					{
						execve(argv[j], &argv[j], envp);
						exit(1);
						/* j++; */
					}
				}
			}
			waitpid(-1, &status, 0);
			j++;
			printf("2 - **POST Strcmp %i\n", j);
		}
		/* if (i <= j ) */
			i = j;
		printf("3 - EXIT Strcmp %i\n", i);
	}
	return (0);

	/* pipe(fd); */
	/* pid = fork(); */

	/* if (pid == 0 && argc > 0) */
	/* { */
	/* 	if (strcmp("cd", argv[i]) == 0) */
	/* 	{ */
	/* 		chdir(argv[i + 1]); */
	/* 		return 0; */
	/* 	} */
	/* 	else */
	/* 	{ */
	/* 		/1* printf("Nooo\n"); *1/ */
	/* 		execve(argv[i], &argv[i], envp); */
	/* 		return 0; */
	/* 	} */
	/* } */
	/* else */
	/* 	waitpid(0, &status, 0); */

}
