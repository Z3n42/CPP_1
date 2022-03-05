/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/03/05 15:23:06 by ingonzal         ###   ########.fr       */
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
	
	pipe(fd);
	pid = fork();

	if (pid == 0 && argc > 0)
	{
		if (strcmp("cd", argv[1]) == 0)
		{
			printf("yess\n");
			return 0;
		}
		execve(argv[1], &argv[1], envp);
	}
	else
		waitpid(0, &status, 0);

}
