#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    int x = enter_size_matrixrow();
    int y = enter_size_matrixcol();
    int* m1 = (int*)malloc(x * y * sizeof(int));
    int* m2 = (int*)malloc(x * y * sizeof(int));
    enter_size_matrix1(m1, x, y);
    enter_size_matrix2(m2, x, y);
    matrixsum(m1, m2, x, y);
    free(m1);
    free(m2);
 }
