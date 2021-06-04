#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int x;
    int y;
//	char str[16];

    x = 1;
    y = 0;
	
if  (argc != 2)
    write(1, "Número de parámetros inadecuados", 33);
//if    (argv[x][y] < '0' || argv[x][y] > '5')
//  write(1, "Valor de los parámetros inadecuado", 34);
//  break;
else
//    while (x < argc)
 //   {
        while (argv[1][y] != '\0')
        {
//            if (argv[x][y] <= '0' && argv[x][y] >= '5')
//                write(1, "Valor de los parámetros inadecuados", 34);
            if (argv[1][y] <= '4' && argv[1][y] >= '1')
			{
//				str[y] = argv[x][y];
                printf("%c", argv[x][y]);
			}
			y++;
        }
     //   x++;
   // }
    return (0);
}
