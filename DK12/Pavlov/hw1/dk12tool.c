#include <stdio.h>
#include <stdlib.h>
#include "dk12tool.h"


int data[3];
int matrix[100][100];

void matrixEnter(void)
{   
    printf("Введіть к-сть рядків:");
    scanf("%d", &data[0]);
    printf("Введіть к-сть стовпчиків:");
    scanf("%d", &data[1]);
    printf("Введіть множник:");
    scanf("%d", &data[2]);
}

void matrCalc(void) 
{
    printf("Введіть числа для матриці:\n");
    for (int i = 0; i < data[0]; i++)
    {
        for (int j = 0; j < data[1]; j++)
        { 
            scanf("%d", &matrix[i][j]);
        }
    }
}

void result(void)
{
    printf("Результат:\n");
    for (int i = 0; i < data[0]; i++)
    {
        for (int j = 0; j < data[1]; j++)
        {
            matrix[i][j] *= data[2];
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
}
