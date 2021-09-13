/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:05:38 by dmarquez          #+#    #+#             */
/*   Updated: 2021/09/03 18:01:42 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>	//Null
# include <stdlib.h>	//malloc
# include <unistd.h>	//read

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int	fd);
size_t	ft_gnl_strlen(char	*s);
int		ft_findc(char	*s, int	c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_line(char *cache);
char	*ft_newcache(char *cache);
char	*ft_gnl_strchr(char	*s, int	c);
void	test_rd(int	rd, char	*buff);

#endif
