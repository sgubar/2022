#include <stdlib.h>
#include "dk_mtrxtool.h"

void mtrx_dtor(Matrix *m)
{
    free(m->ptr);
};
void mtrx_print(Matrix* m)
{
    for(int j = 0; j < m->height; j++)
    {
        printf("\n");

        for(int i = 0; i < m->width; i++)
        {
            printf("%4i\t", m->ptr[j][i]);
        }

        printf("\n");
    }

    printf("\n");
};
Matrix* mtrx_ctor(int width, int height, int *data)
{
    Matrix *result = calloc(1, sizeof(Matrix));
    result->ptr = calloc(height, sizeof(int*));
    result->height = height;
    result->width = width;
    result->hdata = data;

    for(int i = 0; i < height; i++)
    {
        result->ptr[i] = &data[i * width];
    }

    return result;
};
Matrix* mtrx_prod(Matrix *left, Matrix *right)
{
    int lh = left->height;
    int rw = right->width;

    if(left->width != right->height)
    {
        return NULL;
    }

    int *data = calloc(rw * lh, sizeof(int));

    for(int i = 0; i < lh; i++)
    {
        for(int j = 0; j < rw; j++)
        {
            int cell = 0;

            for(int k = 0; k < lh; k++)
            {
                cell += left->ptr[i][k] * right->ptr[k][j];
            }

            data[i * rw + j] = cell;
        }
    }

    return mtrx_ctor(rw, lh, data);
};
Matrix* mtrx_num_prod(Matrix* m, int i);
Matrix* mtrx_sum(Matrix *left, Matrix *right)
{
    int lw = left->width;
    int lh = left->height;
    int rw = right->width;
    int rh = right->height;

    if(lw != rw || lh != rh)
    {
        return NULL;
    }

    Matrix *result = calloc(1, sizeof(Matrix));



    return result;
};
Matrix* mtrx_diff(Matrix *left, Matrix *right);
Matrix* mtrx_trnspse(Matrix *m);