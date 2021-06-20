#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero; 

	numero  = 0;
	
	if (argc != 2)
		printf("Parámetros inadecuados");
	else
		while(argv[1][numero] != '\0')
		{	
			write(1, &argv[1][numero], 1);
			numero++;
		}

}
