#include <stdlib.h>
#include "dk_mtrxtool.h"

void mtrx_dtor(Matrix m)
{
    free(m.ptr);
};
Matrix mtrx_ctor(int width, int height, int values[width * height])
{
    Matrix result;
    int *data[height];

    for(int i = 0; i < height; i++)
    {
        int *p = &values[i * width];
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
    int a = right.ptr[1][0]; // assinges OK

    if(left.width != right.height)
    {
        result.ptr = NULL;
        return result;
    }

    int data[left.height * right.width];

    for(int i = 0; i < left.height; i++)
    {
        for(int j = 0; j < right.width; j++)
        {
            int cell;

            for(int k = 0; k < left.height; k++)
            {
                cell = right.ptr[k][j]; // SEGFAULT
                cell += left.ptr[i][k] * right.ptr[k][j];
            }

            data[i * right.width + j] = cell;
        }
    }

    return mtrx_ctor(right.width, left.height, data);
};
Matrix mtrx_num_prod(Matrix, int);
Matrix mtrx_sum(Matrix left, Matrix right)
{
    Matrix result;

    if(left.width != right.width || left.height != right.height)
    {
        result.ptr = NULL;
    }

    return result;
};
Matrix mtrx_diff(Matrix,Matrix);
Matrix mtrx_trnspse(Matrix);