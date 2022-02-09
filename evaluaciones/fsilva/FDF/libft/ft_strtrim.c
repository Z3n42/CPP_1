/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsilva-f <fsilva-f@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:43:39 by fsilva-f          #+#    #+#             */
/*   Updated: 2021/10/31 22:21:43 by fsilva-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_trim(const char *s1, const char *set, int trim[2]);

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ptr;
	int		len;
	int		trim[2];

	if (!s1)
		return (NULL);
	if (!set)
	{
		len = ft_strlen(s1) + 1;
		trim[0] = 0;
	}
	else if (ft_check_trim(s1, set, trim))
		len = 0;
	else if (trim[0] > trim[1])
		len = 0;
	else
		len = trim[1] - trim[0] + 1;
	ptr = ft_substr(s1, trim[0], (size_t)len);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	return (ptr);
}	

static int	ft_check_trim(const char *s1, const char *set, int trim[2])
{
	size_t	i;
	int		s1_len;
	int		trim_test[2];

	s1_len = (int)ft_strlen(s1);
	if (s1_len == 0)
		return (1);
	trim[0] = 0;
	trim[1] = s1_len - 1;
	trim_test[0] = -1;
	while (trim[0] != trim_test[0] || trim[1] != trim_test[1])
	{
		trim_test[0] = trim[0];
		trim_test[1] = trim[1];
		i = 0;
		while (set[i] != '\0')
		{
			if (s1[trim[0]] == set[i])
				trim[0] = trim[0] + 1;
			if (s1[trim[1]] == set[i] && trim[1] >= 0)
				trim[1] = trim[1] - 1;
			i++;
		}
	}
	return (0);
}
