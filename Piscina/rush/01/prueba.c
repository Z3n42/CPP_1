#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int x;
    int y;
    x = 1;
    y = 0;
if 	(argc != 2)
	write(1, "Número de parámetros inadecuados", 33);
//if	(argv[x][y] < '0' || argv[x][y] > '5')
//	write(1, "Valor de los parámetros inadecuado", 34);
//	break;
else
	while (x < argc)
    {
        while (argv[x][y] != '\0')
        {
            if (argv[x][y] <= '0' && argv[x][y] >= '5')
                write(1, "Valor de los parámetros inadecuados", 34);
			else
                printfe"%c", argv[x][y]);
		            y++;
        }
        x++;
    }
    return (0);
}
