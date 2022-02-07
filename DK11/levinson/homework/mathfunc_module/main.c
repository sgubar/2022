#include <stdlib.h>
#include <stdio.h>
#include "dk_mtrxtool.h"

int main(void)
{
    // int data[] = {  11, 12, 13, 
    //                 21, 22, 23, 
    //                 31, 32, 33  };

    int data[]= { 1, 2, 3, 4 };

    Matrix m1 = mtrx_ctor(2, 2, data);
    Matrix prod = mtrx_prod(m1, m1);

    printf("done");
} 