/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:15:00 by xamayuel          #+#    #+#             */
/*   Updated: 2022/03/22 20:02:16 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * https://www.tutorialspoint.com/c_standard_library/c_function_signal.htm
 * 
 */

#include "minitalk_bonus.h"

void	ft_show_message(int error);
int		ft_all_numeric(char *txt);
void	ft_send_message(int pid, unsigned char c);
void	ft_send_0_message(int pid);

/**
 * DESCRIPTION: cd 
 * 
 * ARGUMENTS: First parameter: ID of server.
 * 			  Second parameter: text to be transmitted.
 */
int	main(int argn, char *argv[])
{
	size_t	i;

	signal(SIGUSR2, ft_show_end);
	signal(SIGUSR1, ft_show_end);
	if (argn < 3)
		ft_show_message(0);
	else
	{
		if (ft_all_numeric(argv[1]) == 0)
			ft_show_message(1);
		else
		{
			i = 0;
			while (i < ft_strlen(argv[2]))
			{
				ft_send_message(ft_atoi(argv[1]), argv[2][i]);
				i++;
			}
			ft_putstr_fd("Sending ", 1);
			ft_putnbr_fd(ft_strlen(argv[2]), 1);
			ft_putstr_fd(" characteres\n", 1);
			ft_send_0_message(ft_atoi(argv[1]));
		}
	}
}
