#include <stdio.h>
#include <stdlib.h>

void matrixsum(int* matrix_1, int* matrix_2, int row_1, int col_1) {

    for (int i = 0; i < row_1; i++) {                                                             //����� ������
        for (int j = 0; j < col_1; j++) {
            *(matrix_1 + i * col_1 + j) = *(matrix_1 + i * col_1 + j) + *(matrix_2 + i * col_1 + j);
        }
    }
}