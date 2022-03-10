/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/03/10 21:06:28 by ingonzal         ###   ########.fr       */
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
	
	pipe(fd);
	i = 1;
	j = i;
	while (i < argc)
	{
		while (argv[j] != NULL || j < argc)
		{
			if (strcmp(argv[j], ";") == 0)
				break;
			pid = fork();
			if (pid == 0 && argc > 0)
			{
				execve(argv[j], &argv[j], envp);
			}
			/* else */
			/* { */
			waitpid(0, &status, 0);
			j++;
			/* } */
		}
		i = j;
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
