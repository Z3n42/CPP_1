/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:01:35 by xamayuel          #+#    #+#             */
/*   Updated: 2022/03/22 20:51:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define TSLEEP 300
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_show_message(int error);
int		ft_all_numeric(char *txt);
void	ft_send_message(int pid, unsigned char c);
void	ft_send_0_message(int pid);
void	ft_show_end(int signum);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
#endif