/bin/ls
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c
out.res
subject.en.txt
subject.fr.txt
test.sh

/bin/cat microshell.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanpipemicro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:20:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/03/30 14:31:53 by ingonzal         ###   ########.fr       */
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
						printf("error: cannot execute %s\n", argv[j]);
					exit(0);
				}
				close(fd[0][1]); 
				waitpid(-1, &status, 0);
				close(fd[0][0]);
				/* close(fd[0][1]); */
				fd[0][0] = fd[1][0];
				fd[0][1] = fd[1][1];
				if (pipe(fd[1]) == -1)
				{
					printf("error: fatal\n");
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
		if (argv[j] != NULL && argv[j] && argv[j][0] == ';')
			sc = 1;
		if (argv[j] != NULL && argv[j] && argv[j][0] == '|')
			sc = 0;
		j++;
	}
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
	return (0);
}

/bin/ls microshell.c
microshell.c

/bin/ls salut

;

; ;

; ; /bin/echo OK
OK

; ; /bin/echo OK ;
OK

; ; /bin/echo OK ; ;
OK

; ; /bin/echo OK ; ; ; /bin/echo OK
OK
OK

/bin/ls | /usr/bin/grep microshell
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c

/bin/ls ewqew | /usr/bin/grep micro | /bin/cat -n ; /bin/echo dernier ; /bin/echo
dernier


/bin/ls | /usr/bin/grep micro | /bin/cat -n ; /bin/echo dernier ; /bin/echo ftest ;
     1	microshell
     2	microshell.c
     3	microshell.dSYM
     4	microshell_old.c
     5	microshell_old_2.c
dernier
ftest

/bin/echo ftest ; /bin/echo ftewerwerwerst ; /bin/echo werwerwer ; /bin/echo qweqweqweqew ; /bin/echo qwewqeqrtregrfyukui ;
ftest
ftewerwerwerst
werwerwer
qweqweqweqew
qwewqeqrtregrfyukui

/bin/ls ftest ; /bin/ls ; /bin/ls werwer ; /bin/ls microshell.c ; /bin/ls subject.fr.txt ;
leaks.res
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c
out.res
subject.en.txt
subject.fr.txt
test.sh
microshell.c
subject.fr.txt

/bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ;
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c
microshell
microshell.c
microshell.dSYM
microshell_old.c
microshell_old_2.c

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b ; /bin/cat subject.fr.txt ;
Ecrire un programme qui aura ressemblera à un executeur de commande shell
- Les executables seront appelés avec un chemin relatif ou absolut mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implementer "|" et ";" comme dans bash
- Votre programme doit implementer la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
- Votre programme n'a pas à gerer les variables d'environment ($BLA ...)
- Si execve echoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ca devrait etre le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" meme si la limite du nombre de "fichier ouvert" est inferieur à 30.
N'oubliez pas de passer les variables d'environment à execve
Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Ecrire un programme qui aura ressemblera à un executeur de commande shell
- La ligne de commande à executer sera passer en argument du programme
- Les executables seront appelés avec un chemin relatif ou absolut mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implementer "|" et ";" comme dans bash
	- Nous n'essaierons jamais un "|" immédiatement suivi ou précédé par rien ou un autre "|" ou un ";"
- Votre programme doit implementer la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
	- si cd a echoué votre programme devra afficher dans STDERR "error: cd: cannot change directory to path_to_change" suivi d'un '\n' avec path_to_change remplacer par l'argument à cd
	- une commande cd ne sera jamais immédiatement précédée ou suivie par un "|"
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
- Votre programme n'a pas à gerer les variables d'environment ($BLA ...)
- Si un appel systeme, sauf execve et chdir, retourne une erreur votre programme devra immédiatement afficher dans STDERR "error: fatal" suivi d'un '\n' et sortir
- Si execve echoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ca devrait etre le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" meme si la limite du nombre de "fichier ouvert" est inferieur à 30.

Par exemple, la commande suivante doit marcher:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Conseils:
N'oubliez pas de passer les variables d'environment à execve

Conseils:
Ne fuitez pas de file descriptor!
/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep w ; /bin/cat subject.fr.txt ;
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Ecrire un programme qui aura ressemblera à un executeur de commande shell
- La ligne de commande à executer sera passer en argument du programme
- Les executables seront appelés avec un chemin relatif ou absolut mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implementer "|" et ";" comme dans bash
	- Nous n'essaierons jamais un "|" immédiatement suivi ou précédé par rien ou un autre "|" ou un ";"
- Votre programme doit implementer la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
	- si cd a echoué votre programme devra afficher dans STDERR "error: cd: cannot change directory to path_to_change" suivi d'un '\n' avec path_to_change remplacer par l'argument à cd
	- une commande cd ne sera jamais immédiatement précédée ou suivie par un "|"
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
- Votre programme n'a pas à gerer les variables d'environment ($BLA ...)
- Si un appel systeme, sauf execve et chdir, retourne une erreur votre programme devra immédiatement afficher dans STDERR "error: fatal" suivi d'un '\n' et sortir
- Si execve echoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ca devrait etre le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" meme si la limite du nombre de "fichier ouvert" est inferieur à 30.

Par exemple, la commande suivante doit marcher:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Conseils:
N'oubliez pas de passer les variables d'environment à execve

Conseils:
Ne fuitez pas de file descriptor!
/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep w ; /bin/cat subject.fr.txt
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Ecrire un programme qui aura ressemblera à un executeur de commande shell
- La ligne de commande à executer sera passer en argument du programme
- Les executables seront appelés avec un chemin relatif ou absolut mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implementer "|" et ";" comme dans bash
	- Nous n'essaierons jamais un "|" immédiatement suivi ou précédé par rien ou un autre "|" ou un ";"
- Votre programme doit implementer la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
	- si cd a echoué votre programme devra afficher dans STDERR "error: cd: cannot change directory to path_to_change" suivi d'un '\n' avec path_to_change remplacer par l'argument à cd
	- une commande cd ne sera jamais immédiatement précédée ou suivie par un "|"
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
- Votre programme n'a pas à gerer les variables d'environment ($BLA ...)
- Si un appel systeme, sauf execve et chdir, retourne une erreur votre programme devra immédiatement afficher dans STDERR "error: fatal" suivi d'un '\n' et sortir
- Si execve echoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ca devrait etre le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" meme si la limite du nombre de "fichier ouvert" est inferieur à 30.

Par exemple, la commande suivante doit marcher:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Conseils:
N'oubliez pas de passer les variables d'environment à execve

Conseils:
Ne fuitez pas de file descriptor!
/bin/cat subject.fr.txt ; /bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b | /usr/bin/grep z ; /bin/cat subject.fr.txt
Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Ecrire un programme qui aura ressemblera à un executeur de commande shell
- La ligne de commande à executer sera passer en argument du programme
- Les executables seront appelés avec un chemin relatif ou absolut mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implementer "|" et ";" comme dans bash
	- Nous n'essaierons jamais un "|" immédiatement suivi ou précédé par rien ou un autre "|" ou un ";"
- Votre programme doit implementer la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
	- si cd a echoué votre programme devra afficher dans STDERR "error: cd: cannot change directory to path_to_change" suivi d'un '\n' avec path_to_change remplacer par l'argument à cd
	- une commande cd ne sera jamais immédiatement précédée ou suivie par un "|"
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
- Votre programme n'a pas à gerer les variables d'environment ($BLA ...)
- Si un appel systeme, sauf execve et chdir, retourne une erreur votre programme devra immédiatement afficher dans STDERR "error: fatal" suivi d'un '\n' et sortir
- Si execve echoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ca devrait etre le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" meme si la limite du nombre de "fichier ouvert" est inferieur à 30.

Par exemple, la commande suivante doit marcher:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Conseils:
N'oubliez pas de passer les variables d'environment à execve

Conseils:
Ne fuitez pas de file descriptor!N'oubliez pas de passer les variables d'environment à execve
Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Ecrire un programme qui aura ressemblera à un executeur de commande shell
- La ligne de commande à executer sera passer en argument du programme
- Les executables seront appelés avec un chemin relatif ou absolut mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implementer "|" et ";" comme dans bash
	- Nous n'essaierons jamais un "|" immédiatement suivi ou précédé par rien ou un autre "|" ou un ";"
- Votre programme doit implementer la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
	- si cd a echoué votre programme devra afficher dans STDERR "error: cd: cannot change directory to path_to_change" suivi d'un '\n' avec path_to_change remplacer par l'argument à cd
	- une commande cd ne sera jamais immédiatement précédée ou suivie par un "|"
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
- Votre programme n'a pas à gerer les variables d'environment ($BLA ...)
- Si un appel systeme, sauf execve et chdir, retourne une erreur votre programme devra immédiatement afficher dans STDERR "error: fatal" suivi d'un '\n' et sortir
- Si execve echoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ca devrait etre le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" meme si la limite du nombre de "fichier ouvert" est inferieur à 30.

Par exemple, la commande suivante doit marcher:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Conseils:
N'oubliez pas de passer les variables d'environment à execve

Conseils:
Ne fuitez pas de file descriptor!
; /bin/cat subject.fr.txt ; /bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b | /usr/bin/grep z ; /bin/cat subject.fr.txt
Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Ecrire un programme qui aura ressemblera à un executeur de commande shell
- La ligne de commande à executer sera passer en argument du programme
- Les executables seront appelés avec un chemin relatif ou absolut mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implementer "|" et ";" comme dans bash
	- Nous n'essaierons jamais un "|" immédiatement suivi ou précédé par rien ou un autre "|" ou un ";"
- Votre programme doit implementer la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
	- si cd a echoué votre programme devra afficher dans STDERR "error: cd: cannot change directory to path_to_change" suivi d'un '\n' avec path_to_change remplacer par l'argument à cd
	- une commande cd ne sera jamais immédiatement précédée ou suivie par un "|"
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
- Votre programme n'a pas à gerer les variables d'environment ($BLA ...)
- Si un appel systeme, sauf execve et chdir, retourne une erreur votre programme devra immédiatement afficher dans STDERR "error: fatal" suivi d'un '\n' et sortir
- Si execve echoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ca devrait etre le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" meme si la limite du nombre de "fichier ouvert" est inferieur à 30.

Par exemple, la commande suivante doit marcher:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Conseils:
N'oubliez pas de passer les variables d'environment à execve

Conseils:
Ne fuitez pas de file descriptor!N'oubliez pas de passer les variables d'environment à execve
Assignment name  : microshell
Expected files   : *.c *.h
Allowed functions: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp
--------------------------------------------------------------------------------------

Ecrire un programme qui aura ressemblera à un executeur de commande shell
- La ligne de commande à executer sera passer en argument du programme
- Les executables seront appelés avec un chemin relatif ou absolut mais votre programme ne devra pas construire de chemin (en utilisant la variable d environment PATH par exemple)
- Votre programme doit implementer "|" et ";" comme dans bash
	- Nous n'essaierons jamais un "|" immédiatement suivi ou précédé par rien ou un autre "|" ou un ";"
- Votre programme doit implementer la commande "built-in" cd et seulement avec un chemin en argument (pas de '-' ou sans argument)
	- si cd n'a pas le bon nombre d'argument votre programme devra afficher dans STDERR "error: cd: bad arguments" suivi d'un '\n'
	- si cd a echoué votre programme devra afficher dans STDERR "error: cd: cannot change directory to path_to_change" suivi d'un '\n' avec path_to_change remplacer par l'argument à cd
	- une commande cd ne sera jamais immédiatement précédée ou suivie par un "|"
- Votre programme n'a pas à gerer les "wildcards" (*, ~ etc...)
- Votre programme n'a pas à gerer les variables d'environment ($BLA ...)
- Si un appel systeme, sauf execve et chdir, retourne une erreur votre programme devra immédiatement afficher dans STDERR "error: fatal" suivi d'un '\n' et sortir
- Si execve echoue votre programme doit afficher dans STDERR "error: cannot execute executable_that_failed" suivi d'un '\n' en ayant remplacé executable_that_failed avec le chemin du programme qui n'a pu etre executé (ca devrait etre le premier argument de execve)
- Votre programme devrait pouvoir accepter des centaines de "|" meme si la limite du nombre de "fichier ouvert" est inferieur à 30.

Par exemple, la commande suivante doit marcher:
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

Conseils:
N'oubliez pas de passer les variables d'environment à execve

Conseils:
Ne fuitez pas de file descriptor!
blah | /bin/echo OK
OK

blah | /bin/echo OK ;
OK

