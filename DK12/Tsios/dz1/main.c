#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <locale.h>


 



int main()
{


    int row_1, col_1;
    int row_2, col_2;
    setlocale(LC_ALL, "Rus");

    printf("Введите количество строк первой матрицы: \n");
    scanf("%d", &row_1);

    printf("Введите количество столбцов первой матрицы: \n");
    scanf("%d", &col_1);

    printf("Введите количество строк второй матрицы: \n");
    scanf("%d", &row_2);

    printf("Введите количество столбцов второй матрицы: \n");
    scanf("%d", &col_2);


    if (col_1 != col_2 || row_1 != row_2) {

        printf("Суммирование матриц невозможно");

    }
    else {

        int* matrix_1 = (int*)malloc(row_1 * col_1 * sizeof(int));
        int* matrix_2 = (int*)malloc(row_2 * col_2 * sizeof(int));



        printf("Введите элементы первой матрицы\n"); //ВВОД 1 МАТРИЦЫ

        for (int i = 0; i < row_1; i++) {
            for (int j = 0; j < col_1; j++) {

                printf("a[%d][%d] = ", i, j);
                scanf("%d", (matrix_1 + i * col_1 + j));
            }
        }

        printf("\nВведите элементы второй матрицы\n"); //ВВОД 2 МАТРИЦЫ
        for (int i = 0; i < row_2; i++) {
            for (int j = 0; j < col_2; j++) {

                printf("a[%d][%d] = ", i, j);
                scanf("%d", (matrix_2 + i * col_2 + j));
            }
        }

        matrixsum(matrix_1, matrix_2, row_1, col_1);

        for (int i = 0; i < row_1; i++) {                                         //ВЫВОД МАТРИЦЫ
            for (int j = 0; j < col_1; j++) {


                printf("%d ", *(matrix_1 + i * col_1 + j));
            }
            printf("\n");
        }
        free(matrix_1);
        free(matrix_2);
    }

    return 0;
}