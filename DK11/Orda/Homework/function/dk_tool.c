#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#include "dk_tool.h"

void input(){
    printf("Введіть розмір матриці, спочаткку кількість рядків, потім стовпців: \n");
    scanf("%i%i", &y, &x);
    a = (int*)malloc(x*y * sizeof(int));
    printf("На яке число множиться матриця: ");
    scanf("%i", &num);
}

void matrix_input(){
    for(i = 0; i < y; i++)
    {
        for(j = 0; j < x; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", (a + i*x + j));
        }
    }
    
}

void matrix_output(){
    for(i = 0; i < y; i++)
    {
        for(j = 0; j < x; j++){
            printf("%d ", *(a + i*x + j)*num);
        }
        printf("\n");
    }
}