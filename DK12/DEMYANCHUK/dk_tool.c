#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "dk_tool.h"

void create_matrix(int*** matrix[], int row, int colls) {
    *matrix = malloc(sizeof(int) * row);
    int* pTemp = *matrix;

    for (int a = 0; a < row; a++) {
        *(pTemp + a) = malloc(sizeof(int) * colls);
    }
}

void fill_matrix(int** matrix[], int row, int colls) {
    for (int a = 0; a < row; a++) {
        for (int i = 0; i < colls; i++) {

            scanf("%d", &matrix[a][i]);
        }
    }
}

void print_matrix(int** matrix[], int row, int colls) {
    printf("Your matrix:\n\n");

    for (int a = 0; a < row; a++) {
        for (int i = 0; i < colls; i++) {
            printf("%d ", matrix[a][i]);
        } printf("\n");
    }

    printf("===========================\n\n");
}

void fraction(int *matrix_1[], int *matrix_2[], int *matrix_3[], int row, int colls) {
    for (int a = 0; a < row; a++) {
        for (int i = 0; i < colls; i++) {
            matrix_3[a][i] = (matrix_1[a][i] - matrix_2[a][i]);
        }
    }
}

void del_matrix(int*** matrix, int colls) {
    for (int a = 0; a < colls; a++) {
        free(matrix[0][a]); 
    }

    free(*matrix);
    *matrix = NULL;
}
