#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

int a = 0;
    int b = 0;
   void EvaluateMatrixMultiplication(void){
    printf("Enter the number of lines:");
    scanf("%d", &a);
    printf("Enter the number of columns:");
    scanf("%d", &b);
    int d = 0;
    printf("Enter multiplier:");
    scanf("%d", &d);

    int* matrix=(int*)malloc(a*b*sizeof(int));
    int i = 0;
    int j = 0;
    printf("Enter matrix numbers:\n");
    do  
    { 
        do  
        {
            scanf("%2d",(matrix+i*b+j));
        j++;
        } 
        while (j < a);
        i++;
        j = 0;
    } 
        while (i < b);
    i = 0;
    j = 0;
    printf("Result:\n");
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        { 
           *(matrix+i*b+j) *= d;
            printf("%2d", * (matrix+i*b+j));
        }
        printf("\n");
    }
    printf("\n");
  free(matrix);
  getch();
   }