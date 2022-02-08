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
Matrix* mtrx_copy(Matrix *m)
{
    int arrlen = m->height * m->width;
    int *data = malloc(sizeof(int) * (arrlen));

    for(int i = 0; i < arrlen; i++)
    {
        data[i] = m->hdata[i];
    }

    return mtrx_ctor(m->width, m->height, data);
}
Matrix* mtrx_ctor(int width, int height, int *data)
{
    Matrix *result = malloc(sizeof(Matrix));
    result->ptr = malloc(sizeof(int*) * height);
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

    int *data = malloc(sizeof(int) * (rw * lh));

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
Matrix* mtrx_num_prod(Matrix* m, int i)
{
    Matrix *new = mtrx_copy(m);

    for(int i = 0; i < m->height; i++)
    {
        for(int j = 0; j < m->width; i++)
        {
            new->ptr[i][j] = m->ptr[i][j] * i;
        }
    }

    return new;
};
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

    int *data = malloc(sizeof(int) * (lw * lh));

    for(int i = 0; i < lh; i++)
    {
        for(int j = 0; j < lw; i++)
        {
            data[i * rw + j] = left->ptr[i][j] + right->ptr[i][j];
        }
    }


    return mtrx_ctor(lw, lh, data);
};
Matrix* mtrx_diff(Matrix *left, Matrix *right)
{
    int lw = left->width;
    int lh = left->height;
    int rw = right->width;
    int rh = right->height;

    if(lw != rw || lh != rh)
    {
        return NULL;
    }

    int *data = malloc(sizeof(int) * (lw * lh));

    for(int i = 0; i < lh; i++)
    {
        for(int j = 0; j < lw; i++)
        {
            data[i * rw + j] = left->ptr[i][j] - right->ptr[i][j];
        }
    }


    return mtrx_ctor(lw, lh, data);
};
Matrix* mtrx_trnspse(Matrix *m);