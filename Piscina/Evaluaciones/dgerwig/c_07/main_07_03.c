///////////////////////
// c07 ex03    dgerwig
///////////////////////

#include <stdio.h>
#include <string.h>
#include "v1/ex03/ft_strjoin.c"

int		main(void)
{
	int		index;
	char	**strs;
	char	*separator;
	char	*result;

	strs = (char**)malloc( 5 * sizeof(strs));
	strs[0] = "El";
	strs[1] = "perro";
	strs[2] = "de San";
	strs[3] = "Roque";
	strs[4] = "No dede salir en pantalla";
	separator = " ";
	index = 0;
	while (index < 5)
	{
		result = ft_strjoin(index, strs, separator);
		printf("Concatena %d strings: $%s$\n", index, result);
		index++;
	}
}
