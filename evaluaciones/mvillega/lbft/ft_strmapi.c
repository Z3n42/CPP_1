#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rtrn;

	i = 0;
	if (!s || (!s && !f))
		return (ft_strdup(""));
	else if (!f)
		return (ft_strdup(s));
	rtrn = ft_strdup(s);
	if (!rtrn)
		return (rtrn = NULL);
	while (s[i])
	{
		rtrn[i] = (*f)(i, s[i]);
		i++;
	}
	return (rtrn);
}
