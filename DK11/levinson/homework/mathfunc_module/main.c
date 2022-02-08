#include <stdlib.h>
#include <stdio.h>
#include "dk_mtrxtool.h"

int main(void)
{
    // int data[] = {  11, 12, 13, 
    //                 21, 22, 23, 
    //                 31, 32, 33  };

    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // int *data = malloc(sizeof(int)*10);
    // for(int i = 0; i < 10; i++)
    // {
    //     data[i] = i + 1;
    // }

    Matrix *m1 = mtrx_ctor(2, 5, (int*)data);
    mtrx_print(m1);

    Matrix *m2 = mtrx_ctor(5, 2, (int*)data);
    mtrx_print(m2);

    Matrix *prod = mtrx_prod(m1, m2);
    mtrx_print(prod);

    Matrix *sum = mtrx_sum(m1, m2);
    mtrx_print(sum);

    Matrix *diff = mtrx_diff(m1, m1);
    mtrx_print(diff);

    Matrix *x2 = mtrx_num_prod(m1, 3);
    mtrx_print(x2);

    Matrix *trans1 = mtrx_trnspse(m1);
    mtrx_print(trans1);
    Matrix *trans2 = mtrx_trnspse(m2);
    mtrx_print(trans2);

    mtrx_dtor(m1);
    mtrx_dtor(m2);
    mtrx_dtor(prod);
    mtrx_dtor(sum);
    mtrx_dtor(diff);
    mtrx_dtor(x2);

    printf("execution completed");
} 