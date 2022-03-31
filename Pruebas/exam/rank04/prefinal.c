/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefinal.c 	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/03/30 20:40:05 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

	pip = 0;
	pid = 0;
	sc = 1;
	j = 0;
	while (j < 2)
	{
		if (pipe(fd[j]) == -1)
		{
			write(2, "error: fatal\n", 13);
			return (0);
		}
		j++;
	}
	j = 1;
	while (argv[j] || j < argc)
	{
		if (argv[j] && argv[j][0] != ';' && argv[j][0] != '|')
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
							write(2, "error: cd: bad arguments\n", 25);
							j = aux;
							continue;
						}
						j = aux;
					}
				}
				if(chdir(argv[j]) == -1)
				{
					aux = 0;
					while (argv[j][aux])
						aux++;
					write(2, "error: cd: cannot change directory to ", 38);
					write(2, argv[j], aux);
					write(2, "\n", 1);
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
				if (strcmp(argv[j], ";") == 0 || strcmp(argv[j], "|") == 0)
					j++;
				pid = fork();
				if (pid == -1)
				{
					write(2, "error: fatal\n", 13);
					return (0);
				}
				if (pid == 0)
				{
					if (pip == 1 && sc == 1)
						dup2(fd[1][1],STDOUT_FILENO);
					if (pip == 1 && sc == 0)
					{
						dup2(fd[0][0],STDIN_FILENO);
						dup2(fd[1][1],STDOUT_FILENO);
					}
					if (pip == 0 && sc == 0)
						dup2(fd[0][0],STDIN_FILENO);
					close(fd[0][0]);
					close(fd[0][1]);
					close(fd[1][0]);
					close(fd[1][1]);
					aux = j;
					while (argv[aux] && argv[aux][0] != ';' && argv[aux][0] != '|')
						aux++;
					argv[aux] = NULL;
					if (execve(argv[j], &argv[j], envp) == -1)
					{
						aux = 0;
						while (argv[j][aux])
							aux++;
						write(2, "error: cannot execute ", 22);
						write(2, argv[j], aux);
						write(2, "\n", 1);
					}
					exit(0);
				}
				close(fd[0][1]); 
				waitpid(-1, &status, 0);
				close(fd[0][0]);
				fd[0][0] = fd[1][0];
				fd[0][1] = fd[1][1];
				if (pipe(fd[1]) == -1)
				{
					write(2, "error: fatal\n", 13);
					return (0);
				}
				aux = j;
				while (argv[aux] && argv[aux][0] != ';' && argv[aux][0] != '|')
					aux++;
				if ((aux - j) != 1)
					j = aux - 1;
				if ((argv[aux + 1]) == NULL)
					break;	
			}
		}
		if (argv[j] && argv[j][0] == ';')
			sc = 1;
		if (argv[j] && argv[j][0] == '|')
			sc = 0;
		j++;
	}
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
	return (0);
}
