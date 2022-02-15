#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>

#include "dk_tool.h"

void input(int* row, int* col, const char* prompt);
void input(int* row, int* col, const char* prompt) {
    if (NULL != prompt) {
        printf("%s", prompt);
    }
    scanf("%d%d", row, col);
}

void sizeOfMatrix1() {
    printf("Розмір 1 матриці:\n");
    printf("\n");
    scanf("%d%d", &m, &n);
    printf("\n");
}

void matrix1() {
    if (n != m) {
        printf("Введено неквадратну матрицю\n");
        exit(EXIT_FAILURE);
    }
    else {
        int a = 0;
        while (a < m) {
            int b = 0;
            while (b < n) {
                printf("Введіть значення [%d][%d] ", a + 1, b + 1);
                scanf("%d", &matr1[a][b]);
                b++;
            }
            a++;
        }
        printf("\n");
    }
}

void sizeOfMatrix2() {
    printf("Розмір 2 матриці:\n");
    printf("\n");
    scanf("%d%d", &p, &q);
    printf("\n");
}
void matrix2() {
    if (p != q) {
        printf("Введено неквадратну матрицю\n");
        exit(EXIT_FAILURE);
    }
    else {
        if (n != p) {
            printf("Матриці не можуть бути перемножені\n");
            exit(EXIT_FAILURE);
        }
        else {
        int a = 0;
        while (a < p) {
            int b = 0;
            while (b < q) {
                printf("Введіть значення [%d][%d] ", a + 1, b + 1);
                scanf("%d", &matr2[a][b]);
                b++;
            }
            a++;
            }
        printf("\n");
        }
    }
}
void mltp() {
    mult[a][b] = 0;
    for (a = 0; a < m; a++) {
        for (b = 0; b < q; b++) {
            for (i = 0; i < p; i++) {
                sum += matr1[a][i] * matr2[i][b];
            }
            mult[a][b] = sum;
            sum = 0;
        }
    }
}
void res() {
    printf("\n");
    for (a = 0; a < m; a++) {
        for (b = 0; b < q; b++)
            printf("%d\t", mult[a][b]);

        printf("\n");
    }
}