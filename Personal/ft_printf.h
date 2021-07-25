/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:00:08 by ingonzal          #+#    #+#             */
/*   Updated: 2021/07/24 14:40:02 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdint.h>
# include <limits.h>

int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_prueba(int n, int fd);
int		ft_putnbr_long(long int n, int fd);
int		ft_putnbr_hex(unsigned int n, int fd);
int		ft_putnbr_hexmay(unsigned int n, int fd);
int		ft_putnbr_p(uintptr_t n, int fd);
int		ft_printf(const char *format, ...);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
