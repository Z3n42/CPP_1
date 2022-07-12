/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgros-al <mgros-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:23:24 by mgros-al          #+#    #+#             */
/*   Updated: 2022/07/10 19:29:25 by mgros-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c){
    write (1, &c, 1);
}


int main(int argc, char const **argv)
{

if (argc > 2)
{
    /* code */
}

    int cols = 4;
  int rows = 4;
    
    int i = 0;
     int d = 0;
    int** array;
    array = malloc(sizeof(int*)*cols);

    while (i < cols)
    {
       array[i] = malloc(sizeof(int)*rows);
       i++;
    }
    

    i = 0;

    int arrayhelp[16];
    if (argc == 2)
    {
        
        while (argv[1][i] != '\0')
        {
         
          if(argv[1][i] == 32){
            i++;
        }
           
             else if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            write(1,"Error",5);
            return 0;
            break;
        }
        else
        {
             arrayhelp[d] = argv[1][i] - '0';
            i++;
            d++;
            
            
        }
        
        }
        
    } else
    {
       
        write(1,"Error",5);
        write(1,"\n",1);
        return (0);
    }
    d = 0;
    int c = 0;
    int j = 0;
    i = 0;

     

    while (c < rows)
    {
        while (j < cols)
        {
           
       
       array[c][j] = arrayhelp[i];
        
        i++;
        j++;

    }
    j = 0;
    c++;
    
      }

int t = 0;
int z = 0;
int arrayprint[4][4];
int g = 1;
int *temp = 0;

                while (t < 4)
                {
                    while (z != g)
                    {

                        arrayprint[t][z]= g;
                        t--;
                        z++;
                        
                    }
                    t = z;
                    z = 0;
                    g++;
                }

                t = 3;
                z = 1;
                g = 1;

                while (z < 4)
                {
                    /* code */


                    while (t >= g)
                    {

                        arrayprint[t][z]= g;
                        t--;
                        z++;
                        
                    }
                    t = z;
                    z = g;
                    g++;
                }

/*
                        t++ z=0
                arrayprint[0][0]= 1;
                            t-- z++
                arrayprint[1][0]= 2;
                arrayprint[0][1]= 2;

                arrayprint[2][0]= 3;
                arrayprint[1][1]= 3;
                 arrayprint[0][2]= 3;

                  arrayprint[3][0]= 4;
                  arrayprint[2][1]= 4;
                   arrayprint[1][2]= 4;
                    arrayprint[0][3]= 4;

-----------


                    arrayprint[3][1]= 1;
                  arrayprint[2][2]= 1;
                   arrayprint[1][3]= 1;

                    arrayprint[3][2]= 2;
                  arrayprint[2][3]= 2;
         



       */
   /*
       if (array[0][0] == 4)
       {
           arrayprint[0][0]= 1;
        arrayprint[1][1]= arrayprint[0][0] * 2;
        arrayprint[2][2]= 1;
       arrayprint[3][3]= arrayprint[2][2] * 2;

       }

       if (array[0][3]==1)
       {
           int u = 0;
           int y = 3;
          while (y > 0)
          {
             arrayprint[u][y]= 4;
             u++;
             y--;
          }
          
       }

       if (array[0][1] == 3 && array[2][1] == 3)
       {
          arrayprint[1][0]= 2;
          arrayprint[0][1]= 2;
       }

          if (array[0][0] == 4 && array[2][0] == 4)
       {
          arrayprint[0][0]= 1;
       }

          if (array[1][3] == 2 && array[3][3] == 2)
       {
          arrayprint[3][3]= 3;
       }

         if (array[1][2] == 2 && array[3][2] == 2)
       {
          arrayprint[3][2]= 2;
          arrayprint[2][3]= 2;
       }

         if (array[1][0] == 1 && array[3][0] == 1)
       {
            int u = 3;
           int y = 1;
          while (u > 0)
          {
             arrayprint[u][y]= 1;
             u--;
             y++;
          }
       }
       
         if (array[1][2] == 2 && array[3][2] == 2)
       {
          arrayprint[3][2]= 2;
          arrayprint[2][3]= 2;
       }

*/
      
       
       
       
       

       

   

t = 0;
z = 0;
while(t < rows)
{
    while(z < cols)
    {
        ft_putchar(arrayprint[t][z] + '0');
        write(1," ",1);
        z++;
    }
    z = 0;
t++;
    printf("\n");
}



    
    
}

