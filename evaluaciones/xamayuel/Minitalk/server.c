/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:15:00 by xamayuel          #+#    #+#             */
/*   Updated: 2022/04/04 18:32:09 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm
 * 
 */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk.h"

void	increment_char(int signum, siginfo_t *info, void *context);
void	ft_show_pid(int pid);
int		ft_pow(int base, int exp);
void	ft_putchar_fd(char c, int fd);

/**
 * DESCRIPTION: MINITALK-SERVER MAIN FUNCTION
 * 
 * ARGUMENTS: None
 * 
 * RETURN: Text received from CLIENT program
 * 
 * CONSIDER: signal and pause inside infinite while
 */
int	main(void)
{
	struct sigaction	s_sigaction;

	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = 0;
	ft_show_pid(getpid());
	s_sigaction.sa_sigaction = increment_char;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
	{
		pause();
	}	
}

/**
 * DESCRITPTION: Function to show a 8bits character by signals
 * 
 * ARGUMENTS: signum: SIGUSR1 to add bit = 1
 * 					  SIGUSR2 to add bit = 0
 */
void	increment_char(int signum, siginfo_t *info, void *context)
{
	static int		num = 0;
	static int		bit = 0;
	unsigned char	c;

	(void)context;
	bit ++;
	if (signum == SIGUSR1)
		num = num + ft_pow(2, (bit - 1));
	if (bit % 8 == 0)
	{
		bit = 0;
		if (num > 0)
		{
			c = num;
			num = 0;
			ft_putchar_fd(c, 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			kill(info->si_pid, SIGUSR2);
	}
}

/**
 * DESCRIPTION: Function to show sever PID.
 * 
 * RETURN: Server PID (int) 
 */
void	ft_show_pid(int pid)
{
	char	*txt_pid;

	txt_pid = ft_itoa(pid);
	write(1, "PID IS [", 8);
	write(1, txt_pid, ft_strlen(txt_pid));
	write(1, "]\n", 2);
	free(txt_pid);
}

/**
 * DESCRIPTION: Function to power base to exponent
 * 
 * ARGUMENTS: base: base to be powered
 * 			  exp: exponential value
 * 
 * RETURN: base^exp 
 */
int	ft_pow(int base, int exp)
{
	if (exp == 0)
		return (1);
	else if (exp == 1)
		return (base);
	else
		return (base * ft_pow(base, exp - 1));
}
