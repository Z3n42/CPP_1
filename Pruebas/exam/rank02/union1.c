#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;
	int j;
	int k;
	int z;
		
	if(argc != 3)
		write(1, "\n", 1);
	i = 0;
	j = 0;
	k = 0;
	write(1, &argv[1][0], 1);
	while(argv[1][i])
	{
		/* printf("1st while\n"); */
		while(argv[1][j])
		{
			/* printf("2nd while\n"); */
			while((k < i))
			{
				/* printf("3rd while\n"); */
				if (argv[1][k] == argv[1][i])
				{
					i++;
					/* printf("I =>%d\n", i); */
				}
				else if((argv[1][i] == argv[1][j])/* && (argv[1][k] != argv[1][i])*/ && (i == j))
				{
					/* printf("Print\n"); */
					/* printf("%c\n", argv[1][i]); */
					printf("\nI: %c,%d / J: %c,%d / K: %c,%d\n", argv[1][i], i, argv[1][j], j, argv[1][k], k);
					write(1, &argv[1][i], 1);
					i++;
				}
				k++;			
			}
			j++;
			k = 0;
		}
		if(argv[1][i])
			i++;
		j = 0;
	}
	i = 0;
	j = 0;
	k = 0;
	z = 0;
	while(argv[2][i])
	{
		/* printf("1st while\n"); */
		while(argv[2][j])
		{
			/* printf("2nd while\n"); */
			while((k < i))
			{
				/* printf("3rd while\n"); */
				if (argv[2][k] == argv[2][i])
				{
					i++;
					/* printf("I =>%d\n", i); */
				}
				else if((argv[2][i] == argv[2][j])/* && (argv[1][k] != argv[1][i])*/ && (i == j))
				{
					/* printf("Print\n"); */
					/* printf("%c\n", argv[1][i]); */
					/* printf("\nI: %c,%d / J: %c,%d / K: %c,%d\n", argv[2][i], i, argv[2][j], j, argv[2][k], k); */
					/* while (argv[2][z]) */
					/* { */
					/* 	if(argv[1][z] != argv[2][i]) */
					/* 	{ */
							printf("1 =>%c 2=>%c \n", argv[1][z], argv[2][i]);
							printf("\nI2: %c,%d / J2: %c,%d / K2: %c,%d\n", argv[2][i], i, argv[2][j], j, argv[2][k], k);
							write(1, &argv[2][i], 1);
							i++;
						/* } */
						/* z++; */
					/* } */
					/* z = 0; */
					/* i++; */
				}
				k++;			
			}
			j++;
			k = 0;
		}
		if(argv[2][i])
			i++;
		j = 0;
	}
}
