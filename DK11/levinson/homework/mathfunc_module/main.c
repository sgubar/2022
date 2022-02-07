#include <stdlib.h>
#include <stdio.h>
#include "dk_mtrxtool.h"

int main(void)
{
    // int data[] = {  11, 12, 13, 
    //                 21, 22, 23, 
    //                 31, 32, 33  };

    int data[]= { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    Matrix *m1 = mtrx_ctor(3, 3, (int*)data);
    Matrix *prod = mtrx_prod(m1, m1);

    mtrx_print(prod);
} 