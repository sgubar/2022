#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 0;
    int b = 0;
    printf("Введіть к-сть рядків:");
    scanf("%d", &a);
    printf("Введіть к-сть стовпчиків:");
    scanf("%d", &b);
    int d = 0;
    printf("Введіть множник:");
    scanf("%d", &d);

    int matrix[a][b];
    int i = 0;
    int j = 0;
    printf("Введіть числа для матриці:\n");
    do  
    { 
        do  
        {
            scanf("%d", &matrix[i][j]);
        j++;
        } 
        while (j < a);
        i++;
        j = 0;
    } 
        while (i < b);
    i = 0;
    j = 0;
    printf("Результат:\n");
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        { 
            matrix[i][j] *= d;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
