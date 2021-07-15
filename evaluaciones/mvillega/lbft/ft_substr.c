#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtrn;
	size_t	i;

	if (!s)
		return (NULL);
	if ((int)start > ft_strlen(s))
		return (ft_strdup(""));
	rtrn = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!rtrn)
		return (0);
	while (i < len)
	{
		rtrn[i] = *(s + start + i);
		i++;
	}
	rtrn[i] = '\0';
	return (rtrn);
}
