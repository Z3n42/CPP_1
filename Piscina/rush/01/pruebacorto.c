#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int y;

    y = 0;

if  (argc != 2)
{
	write(1, "Número de parámetros inadecuados", 34);
	write(1, "\n", 1);
}
else
        while (argv[1][y] != '\0')
        {
            if (argv[1][y] <= '4' && argv[1][y] >= '1')     
				write(1, &argv[1][y], 1);
			if ( argv[1][y] >= '5')
			{
				write(1, "Valor de los parámetros inadecuados\n", 35);
				write(1, "\n", 1);
				break;
			}
        y++;
        } 
    return (0);
}
