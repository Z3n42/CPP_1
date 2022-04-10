/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:57:09 by xamayuel          #+#    #+#             */
/*   Updated: 2022/03/22 20:52:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

/**
 * DESCRIPTION: Function to return stdout message.
 * 
 * ARGUMENTS: error: message to be shown.
 * 
 * RETURN: None
 * 
 */
void	ft_show_message(int error)
{
	if (error == 1)
		ft_putstr_fd("\t Error: First parameter should be numeric!", 1);
	if (error < 2)
		ft_putstr_fd("\n\t Usage: ./client [server_pid] [message]", 1);
	ft_putstr_fd("\n", 1);
}

/**
 * DESCRIPTION: Function to check if all characters are numeric
 * 
 * ARGUMENTS: Text to be checked.
 * 
 * RETURN: 1 if al numeric, 0 otherwise.
 */
int	ft_all_numeric(char *txt)
{
	int	i;

	i = 0;
	while (txt[i] != '\0')
	{
		if (ft_isdigit(txt[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * DESCRIPTION: Function to send by signals a 8bits character
 * 
 * ARGUMENTS: pid: server process ID.
 * 			    c: character to be sent.
 * RETURN: None
 * 
 * TIPS: Be careful with the usleep value.
 * 		 DEBIAN_WLS--> usleep(300) works
 */
void	ft_send_message(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c % 2 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c / 2;
		usleep(300);
		i++;
	}
}

/**
 * DESCRIPTION: Function to send '\0' equivalente character
 * 
 * ARGUMENT: pid: server process ID
 *
 * RETURN: None 
 */
void	ft_send_0_message(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(300);
		i++;
	}
}

/**
 * DESCRIPTION: Show client final status message
 * 
 * ARGUMENTS: signum : signal 
 */
void	ft_show_end(int signum)
{
	static int	c = 0;

	if (signum == SIGUSR1)
		c++;
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("\033[0;32mTransmission done:\033[1;30m", 1);
		ft_putnbr_fd(c, 1);
		ft_putstr_fd(" characteres sent\n", 1);
		exit(0);
	}
}
