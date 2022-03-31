/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanpipemicro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/03/30 14:09:53 by ingonzal         ###   ########.fr       */
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
	int pip;
	int sc;
	int	aux;
	int dir;

	pip = 0;
	pid = 0;
	sc = 1;
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
	printf(" 01º CREATE - FD[0][0] = %d\n", fd[0][0]);
	printf(" 02º CREATE - FD[0][1] = %d\n", fd[0][1]);
	printf(" 03º CREATE - FD[1][0] = %d\n", fd[1][0]);
	printf(" 04º CREATE - FD[1][1] = %d\n", fd[1][1]);
	j = 1;
	while (argv[j] || j < argc)
	{
		if (argv[j] != NULL && argv[j] && argv[j][0] != ';' && argv[j][0] != '|')
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
							continue;
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
				pip = 0;
				aux = j;
				while (argv[aux] && argv[aux][0] != ';')
				{
					if (strcmp(argv[aux], "|") == 0)
					{
						pip++;
						break;
					}
					aux++;
				}
				printf("Pipes->%i, Semicolon->%i\n", pip, sc);
				if (strcmp(argv[j], ";") == 0 || strcmp(argv[j], "|") == 0)
					j++;
				/* if (pip == 1 && sc == 1) */
				/* { */
				/* 		printf(" 1 - 1  CLOSE - FD[0][1] = %d\n", fd[0][0]); */
				/* 		close(fd[0][0]); */
				/* 		/1* close(fd[0][1]); *1/ */
				/* 		/1* close(fd[1][0]); *1/ */
				/* } */
				/* if ((pip == 1 && sc == 0)) */
				/* { */
				/* 		/1* close(fd[0][0]); *1/ */
				/* 		printf(" ***** 1 - 0 CLOSE  - FD[1][0] = %d\n", fd[1][0]); */
				/* 		/1* close(fd[1][1]); *1/ */
				/* 		/1* printf(" 2º DUP IN  - FD[0][0] = %d\n", fd[0][0]); *1/ */
				/* 		/1* printf(" 3º DUP OUT - FD[1][1] = %d\n", fd[1][1]); *1/ */
				/* } */
				/* if (pip == 0 && sc == 0) */
				/* { */
				/* 		printf(" ***** 0 - 0 CLOSE  - FD[1][1] = %d\n", fd[1][1]); */
				/* 		close(fd[1][1]); */
				/* 		/1* close(fd[1][0]); *1/ */
				/* 		/1* close(fd[1][1]); *1/ */
				/* } */
				pid = fork();
				if (pid == -1)
				{
					printf("error: fatal\n");
					return (0);
				}
				if (pid == 0)
				{
					if (pip == 1 && sc == 1)
					{
						printf(" 1º DUP IN - FD[1][1] = %d\n", fd[1][1]);
						/* close(fd[0][0]); */
						/* close(fd[0][1]); */
						/* close(fd[1][0]); */
						dup2(fd[1][1],STDOUT_FILENO);
					}
					if (pip == 1 && sc == 0)
					{
						printf(" 2º DUP IN  - FD[0][0] = %d\n", fd[0][0]);
						printf(" 3º DUP OUT - FD[1][1] = %d\n", fd[1][1]);
						dup2(fd[0][0],STDIN_FILENO);
						dup2(fd[1][1],STDOUT_FILENO);
					}
					if (pip == 0 && sc == 0)
					{
						printf(" 4º DUP IN - FD[0][0] = %d\n", fd[0][0]);
						/* close(fd[0][1]); */
						/* close(fd[1][0]); */
						/* close(fd[1][1]); */
						dup2(fd[0][0],STDIN_FILENO);
					}
					/* if (pip == 0 && sc == 1) */
					/* { */
						close(fd[0][0]);
						close(fd[0][1]);
						close(fd[1][0]);
						close(fd[1][1]);
					/* } */
					aux = j;
					while (argv[aux] && argv[aux][0] != ';' && argv[aux][0] != '|')
						aux++;
					argv[aux] = NULL;
					printf("A  %s\n", argv[j]);
					if (execve(argv[j], &argv[j], envp) == -1)
						printf("error: cannot execute %s\n", argv[j]);
					printf("B  %s\n", argv[j]);
					exit(0);
				}
				/* printf(" *****1 CLOSE - FD[1][1] = %d\n", fd[1][1]); */
				/* close(fd[1][1]); */
				/* printf(" *****2 CLOSE - FD[0][1] = %d\n", fd[0][1]); */
				close(fd[0][1]); 
				/* close(fd[1][1]); */ 
				waitpid(-1, &status, 0);
				printf(" 5º CLOSE - FD[0][0] = %d\n", fd[0][0]);
				printf(" 6º CLOSE - FD[0][1] = %d\n", fd[0][1]);
				printf(" 7º EQUAL - FD[1][0] = %d\n", fd[1][0]);
				printf(" 8º EQUAL - FD[1][1] = %d\n", fd[1][1]);
				close(fd[0][0]);
				close(fd[0][1]);
				fd[0][0] = fd[1][0];
				fd[0][1] = fd[1][1];
				/* close(fd[1][0]); */
				/* close(fd[1][1]); */
				printf(" 9º RECIBE - FD[0][0] = %d\n", fd[0][0]);
				printf(" 10º RECIBE - FD[0][1] = %d\n", fd[0][1]);
				/* printf(" 11º  CLOSE - FD[1][0] = %d\n", fd[1][0]); */
				/* printf(" 12º CLOSE - FD[1][1] = %d\n", fd[1][1]); */
				if (pipe(fd[1]) == -1)
				{
					printf("error: fatal\n");
					return (0);
				}
				printf(" 13º FD[0][0] = %d\n", fd[0][0]);
				printf(" 14º FD[0][1] = %d\n", fd[0][1]);
				printf(" 15º CREA FD[1][0] = %d\n", fd[1][0]);
				printf(" 16º CREA FD[1][1] = %d\n", fd[1][1]);
				aux = j;
				while (argv[aux] && argv[aux][0] != ';' && argv[aux][0] != '|')
					aux++;
				if ((aux - j) != 1)
					j = aux - 1;
				if ((argv[aux + 1]) == NULL)
				{
					close(fd[0][0]);
					close(fd[0][1]);
					close(fd[1][0]);
					close(fd[1][1]);
					/* return (0); */
					break;	
				}
				
			}
		}
		if (argv[j] != NULL && argv[j] && argv[j][0] == ';')
			sc = 1;
		if (argv[j] != NULL && argv[j] && argv[j][0] == '|')
			sc = 0;
		j++;
	}
	printf(" 17º CLOSE - FD[0][0] = %d\n", fd[0][0]);
	printf(" 18º CLOSE - FD[0][1] = %d\n", fd[0][1]);
	printf(" 19º EQUAL - FD[1][0] = %d\n", fd[1][0]);
	printf(" 20º EQUAL - FD[1][1] = %d\n", fd[1][1]);
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
	return (0);
}
