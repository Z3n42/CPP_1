/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarquez <dmarquez@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 18:14:50 by Dmarquez          #+#    #+#             */
/*   Updated: 2021/09/03 18:03:20 by dmarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	test_rd(int	rd, char	*buff)
{
	if (rd == -1)
		free(buff);
}

char	*get_next_line(int	fd)
{
	char		*line;
	char		*buff;
	static char	*cache;
	int			rd;

	rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_gnl_strchr(cache, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		test_rd(rd, buff);
		if (rd == -1)
			return (NULL);
		buff[rd] = '\0';
		cache = ft_gnl_strjoin(cache, buff);
	}
	free(buff);
	line = ft_line(cache);
	cache = ft_newcache(cache);
	return (line);
}
