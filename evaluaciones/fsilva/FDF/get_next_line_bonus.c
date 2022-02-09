/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:29:41 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/06 12:35:33 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char			*buf;
	static t_node	*head;
	char			*tmp1;
	int				ret[2];

	if (fd < 0)
		return (NULL);
	tmp1 = del_node_key(&head, fd);
	ret[0] = 1;
	ret[1] = fd;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	buf[0] = '\0';
	buf = process_file(&tmp1, ret, &buf, &head);
	if (buf != NULL)
		return (buf);
	if (tmp1 != NULL)
		return (ft_subs_gnl(&tmp1, 0, ft_lenchr(tmp1, '\0'), 1));
	return (NULL);
}

char	*process_file(char **tmp1, int ret[2], char **buf, t_node **head)
{	
	while (ret[0] > 0)
	{
		if (*tmp1 != NULL)
		{
			if (((*buf)[0] != '\0' && ft_lenchr(*buf, '\n') != -1) || \
				((*buf)[0] == '\0' && *tmp1 != NULL && \
				(ft_lenchr(*tmp1, '\n') != -1)))
			{	
				free(*buf);
				return (check_nl(tmp1, head, ret[1]));
			}
		}
		ret[0] = read(ret[1], *buf, BUFFER_SIZE);
		(*buf)[ret[0]] = '\0';
		if (*tmp1 != NULL && ret[0] != 0)
		{
			*tmp1 = ft_strjoin_gnl(tmp1, *buf);
			ret[0] = ft_lenchr(*tmp1, '\0');
		}
		else if (ret[0] > 0)
			*tmp1 = ft_subs_gnl(buf, 0, ret[0], 0);
	}
	free(*buf);
	return (NULL);
}

char	*check_nl(char **tmp1, t_node **head, int fd)
{
	int		index;
	int		ret;
	char	*tmp2;

	index = 0;
	ret = ft_lenchr(*tmp1, '\0');
	while (index < ret)
	{
		if ((*tmp1)[index] == '\n')
		{
			tmp2 = ft_subs_gnl(tmp1, 0, index + 1, 0);
			*tmp1 = ft_subs_gnl(tmp1, index + 1, ret - (index + 1), 1);
			if (*tmp1 != NULL)
			{
				if (add_new_node(head, tmp1, fd))
					return (NULL);
			}
			return (tmp2);
		}
		index = index + 1;
	}
	return (0);
}

int	ft_lenchr(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != '\0')
		i++;
	if (c == '\0')
		return (i);
	else
	{
		while (j <= i)
		{
			if (s[j] == c)
				return (j);
			j++;
		}
	}
	return (-1);
}
