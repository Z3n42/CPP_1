/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01prugnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:33:23 by ingonzal          #+#    #+#             */
/*   Updated: 2021/09/22 21:30:12 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	ft_strlen(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		id (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		id (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*array;

	array = (char *)malloc((ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1) * sizeof(char));
	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof 1);
		s1[0] = '\0';
	}
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		arrai[i + j] = s2[j];
		j++;
	}
	array[i + j] = '\0';
	free(s1);
	return (array);
}

char *ft_substr(char *str, int start, int len)
{
	int i;
	char *array;

	i = 0;
	array = (char *)malloc(sizeof(char) * (len + 1));
	while (str[start + i] && i < len)
	{
		array[i] = str[start + i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char *ft_substr2(char *str, int start, int len)
{
	int i;
	char *array;

	i = 0;
	if (!ft_strchr(str, '\n'))
	{
		free(str);
		return (NULL);
	}
	array = (char *)malloc(sizeof(char) * (len + 1));
	while (str[start + i] && i < len)
	{
		array[i] = str[start + i];
		i++;
	}
	array[i] = '\0';
	free(array);
	return (array);
}

char *get_next_line(int fd)
{
	char		*buff;
	static char *array;
	int			res;
	int 		end;

	if (BUFFER_SIZE < 1 || fd == -1 || fd == 2)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = 1;
	while (res && !ft_srchr(char, '\n'))
	{
		res = read(fd, buff, BUFFER_SIZE);
		if (res < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[res] = '\0';
		array = ft_strjoin(array, buff);
	}
	free(buff);
	end = ft_strlen(array, '\n');
	buff = ft_substr(array, 0, end + 1);
	array = ft_substr_2(array, (end + 1), (st_strlen(array, 0) - ft_strlen(buff, 0));
	if (!res && !ft_strlen(buff, 0))
	{
		free(buff);
		return(NULL);
	}
	return (buff);
}
