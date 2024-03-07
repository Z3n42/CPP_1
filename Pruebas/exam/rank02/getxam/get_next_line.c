#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

/* int	len(char *str, char c) */
/* { */
/* 	int	i; */

/* 	i = 0; */
/* 	if (!str) */
/* 		return (0); */
/* 	while (str[i]) */
/* 	{ */
/* 		if (str[i] == c) */
/* 			return (i); */
/* 		i++; */
/* 	} */
/* 	return (i); */
/* } */

/* int	ft_strchr(char *str, char c) */
/* { */
/* 	int	i; */

/* 	i = 0; */
/* 	if (!str) */
/* 		return (0); */
/* 	while (str[i]) */
/* 	{ */
/* 		if (str[i] == c) */
/* 			return (1); */
/* 		i++; */
/* 	} */
/* 	return (0); */
/* } */

/* char *joinstr(char *s1, char *s2) */
/* { */
/* 	int		i; */
/* 	int		j; */
/* 	char	 *n_str; */

/* 	n_str = (char *)malloc(sizeof(char) * (len(s1, 0) + len(s2, 0) + 1)); */
/* 	i = -1; */
/* 	j = -1; */

/* 	if (!s1) */
/* 	{ */
/* 		s1 = malloc(1); */
/* 		*s1 = 0; */
/* 	} */
/* 	while (s1[++i]) */
/* 		n_str[i] = s1[i]; */
/* 	while (s2[++j]) */
/* 		n_str[i + j] = s2[j]; */
/* 	n_str[i + j] = 0; */
/* 	free(s1); */
/* 	return (n_str); */
/* } */

/* char *cutstr(char *str, int start, int len, int on) */
/* { */
/* 	int	i; */
/* 	char *n_str; */

/* 	i = 0; */
/* 	if (on && !ft_strchr(str, 10)) */
/* 	{ */
/* 		free(str); */
/* 		return (NULL); */
/* 	} */
/* 	n_str = (char *)malloc(sizeof(char) * (len + 1)); */
/* 	while (str[start + i] && i < len) */
/* 	{ */
/* 		n_str[i] = str[start + i]; */
/* 		i++; */
/* 	} */
/* 	n_str[i] = 0; */
/* 	if (on) */
/* 		free(str); */
/* 	return (n_str); */
/* } */

/* char *get_next_line(int fd) */
/* { */
/* 	char 		*buff; */
/* 	static char *kept; */
/* 	int			size; */

/* 	if (BUFFER_SIZE < 1 || fd == -1 || fd == 2) */
/* 		return (NULL); */
/* 	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); */
/* 	size = 1; */
/* 	while (size && !ft_strchr(kept, 10)) */
/* 	{ */
/* 		size = read(fd, buff, BUFFER_SIZE); */
/* 		if (size < 0) */
/* 		{ */
/* 			free(buff); */
/* 			return (NULL); */
/* 		} */
/* 		buff[size] = 0; */
/* 		kept = joinstr(kept, buff); */
/* 	} */
/* 	free(buff); */
/* 	buff = cutstr(kept, 0, len(kept, 10) + 1, 0); */
/* 	kept = cutstr(kept, len(buff, 0), len(kept, 0) - len(buff, 0), 1); */
/* 	if (!size && !len(buff, 0)) */
/* 	{ */
/* 		free(buff); */
/* 		return (NULL); */
/* 	} */
/* 	return (buff); */
/* } */

int	ft_strlen(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
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
		if (str[i] == c)
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
		array[i + j] = s2[j];
		j++;
	}
	array[i + j] = '\0';
	free(s1);
	return (array);
}

char *ft_substr2(char *str, int start, int len)
{
	int 	i;
	char	*array;

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
	free(str);
	return (array);
}

char *ft_substr(char *str, int start, int len)
{
	int 	i;
	char	*array;

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

char *get_next_line(int fd)
{
	char			*buff;
	static char		*array;
	int				res;
	int				end;

	if (BUFFER_SIZE < 1 || fd == -1 || fd == 2)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = 1;
	while (res && !ft_strchr(array, '\n'))
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
	array = ft_substr2(array, (end + 1), (ft_strlen(array, 0) - ft_strlen(buff, 0)));
	if (!res && !ft_strlen(buff, 0))
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}
