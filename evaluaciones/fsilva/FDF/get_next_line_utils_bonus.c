/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:32:11 by fsilva-f          #+#    #+#             */
/*   Updated: 2022/02/06 12:40:00 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

/*
ft_subs_gnl: like substr, but frees the string s inside the function
*/
char	*ft_subs_gnl(char **s, int start, int len, int s_free)
{
	char	*ptr;
	int		i;
	int		s_len;

	if (s == NULL)
		return (NULL);
	ptr = NULL;
	s_len = (int)ft_lenchr(*s, '\0');
	if (s_len - start <= len)
		len = s_len - start;
	if (len > 0)
		ptr = (char *)malloc(len + 1);
	if (ptr != NULL)
	{
		i = -1;
		while (++i < len && ((*s)[start + i] != '\0'))
			ptr[i] = (*s)[start + i];
		ptr[i] = '\0';
	}
	if (s_free)
	{
		free(*s);
		*s = NULL;
	}
	return (ptr);
}

char	*ft_strjoin_gnl(char **tmp1, char *buf)
{
	int		tmp1_len;
	int		buf_len;
	char	*ptr;
	int		i;

	if (*tmp1 == NULL || buf == NULL)
		return (NULL);
	tmp1_len = ft_lenchr(*tmp1, '\0');
	buf_len = ft_lenchr(buf, '\0');
	ptr = (char *)malloc(tmp1_len + buf_len + 1);
	if (ptr == NULL)
		return (NULL);
	i = -1;
	while (++i < tmp1_len)
		ptr[i] = (*tmp1)[i];
	while (i < tmp1_len + buf_len)
	{
		ptr[i] = buf[i - tmp1_len];
		i++;
	}
	ptr[i] = '\0';
	free(*tmp1);
	*tmp1 = NULL;
	return (ptr);
}

int	add_new_node(t_node **head, char **content, int key)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof (t_node));
	if (tmp == NULL)
		return (1);
	else
	{
		tmp->data = ft_subs_gnl(content, 0, ft_lenchr(*content, '\0'), 1);
		tmp->next = NULL;
		tmp->key = key;
	}
	if (*head == NULL)
		*head = tmp;
	else
	{
		tmp->next = *head;
		*head = tmp;
	}
	return (0);
}

char	*del_node_key(t_node **head, int key)
{
	t_node	*current;
	t_node	*previous;
	char	*content;

	if (*head == NULL)
		return (NULL);
	current = *head;
	previous = NULL;
	while (current->key != key)
	{
		if (current->next == NULL)
			return (NULL);
		else
		{
			previous = current;
			current = current->next;
		}
	}
	if (current == *head)
		*head = (*head)->next;
	else
		previous->next = current->next;
	content = ft_subs_gnl(&current->data, 0, ft_lenchr(current->data, '\0'), 1);
	free(current);
	return (content);
}
