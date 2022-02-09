#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include "math.h"

int main()
{
    int **matrix = create_matrix(3,3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            *(*(matrix + i) + j) = get_int("a[%d][%d]=",i,j);
        }
    }
printf("Матриця\n");
printarray((int **)matrix,3);
int n=0;int m=0;
    while(n<2)
    {
        m=0;
        while(m<3)
        {
            if(n==1 && m==0)
            {
                m++;
            }else{
            int k = *(*(matrix + n) + m);
            *(*(matrix + n) + m) = *(*(matrix + m) + n);
            *(*(matrix + m) + n) = k;
            m++;
            }
        }
    n++;
    }
    printf("Транспонована Матриця\n");
    printarray((int **)matrix,3);
    delete_matrix((int **)matrix,3);
    return 0;
}
