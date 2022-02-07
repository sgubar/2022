#include <stdlib.h>
#include "dk_mtrxtool.h"

void mtrx_dtor(Matrix m)
{
    free(m.ptr);
};
Matrix mtrx_ctor(int width, int height, int values[width*height])
{
    Matrix result;
    int **data = malloc(sizeof(int*) * height);

    for(int i = 0; i < height; i++)
    {
        int *p = &values[width * (i + 1)];
        data[i] = p;
    }

    result.height = height;
    result.width = width;
    result.ptr = data;

    return result;
};
Matrix mtrx_prod(Matrix left, Matrix right)
{
    Matrix result;

    if(left.width != right.height)
    {
        result.ptr = NULL;
    }
};
Matrix mtrx_num_prod(Matrix, int);
Matrix mtrx_sum(Matrix,Matrix);
Matrix mtrx_diff(Matrix,Matrix);
Matrix mtrx_trnspse(Matrix);