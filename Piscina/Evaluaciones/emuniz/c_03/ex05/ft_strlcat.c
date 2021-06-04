unsigned int	ft_count(char *string);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	v;

	i = ft_count(src);
	j = ft_count(dest);
	v = i + j;
	if (size == 0)
		return (v);
	i = 0;
	j = 0;
	if (size > 0)
	{
		while (dest[i] != '\0')
			i++;
		while ((i + j) < (size - 1) && src[j] != '\0')
		{
			dest[i + j] = src[j];
			j++;
		}
	}
	dest[i + j] = '\0';
	return (v);
}

unsigned int	ft_count(char *string)
{
	unsigned int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
