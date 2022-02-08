#include <stdlib.h>
#include "dk_mtrxtool.h"

void mtrx_dtor(Matrix *m)
{
    free(m->ptr[0]);
    free(m->ptr);
    free(m);
};
void mtrx_print(Matrix* m)
{
    if(m == NULL)
    {
        printf("NULL pointer passed to mtrx_print funciton!");
        return NULL;
    }

    printf("\n============================================================================\n");

    for(int i = 0; i < m->height; i++)
    {
        printf("\n");

        for(int j = 0; j < m->width; j++)
        {
            printf("%4i\t", m->ptr[i][j]);
        }

        printf("\n");
    }

    printf("\n============================================================================\n");
};
Matrix* mtrx_copy(Matrix *m)
{
    if(m == NULL)
    {
        printf("NULL pointer passed to mtrx_copy funciton!");
        return NULL;
    }
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
    if(data == NULL)
    {
        printf("NULL pointer passed to mtrx_ctor funciton!");
        return NULL;
    }
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
    if(left == NULL || right == NULL)
    {
        printf("NULL pointer passed to mtrx_prod funciton!");
        return NULL;
    }

    if(left->width != right->height)
    {
        printf("Mismatched matrices passed to mtrx_prod funciton!");
        return NULL;
    }

    int *data = malloc(sizeof(int) * (right->width * left->height));

    for(int i = 0; i < left->height; i++)
    {
        for(int j = 0; j < right->width; j++)
        {
            int cell = 0;

            for(int k = 0; k < left->width; k++)
            {
                cell += left->ptr[i][k] * right->ptr[k][j];
            }

            data[i * right->width + j] = cell;
        }
    }

    return mtrx_ctor(right->width, left->height, data);
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
    if(left == NULL || right == NULL)
    {
        printf("NULL pointer passed to mtrx_sum funciton!");
        return NULL;
    }

    if(left->width != right->width || left->height != right->height)
    {
        printf("Mismatched matrices passed to mtrx_sum funciton!");
        return NULL;
    }

    int lw = left->width;
    int lh = left->height;
    int rw = right->width;
    int rh = right->height;
    int *data = malloc(sizeof(int) * (lw * lh));

    for(int i = 0; i < lh; i++)
    {
        for(int j = 0; j < lw; j++)
        {
            data[i * rw + j] = left->ptr[i][j] + right->ptr[i][j];
        }
    }


    return mtrx_ctor(lw, lh, data);
};
Matrix* mtrx_diff(Matrix *left, Matrix *right)
{
    if(left == NULL || right == NULL)
    {
        printf("NULL pointer passed to mtrx_diff funciton!");
        return NULL;
    }

    if(left->width != right->width || left->height != right->height)
    {
        printf("Mismatched matrices passed to mtrx_diff funciton!");
        return NULL;
    }

    int lw = left->width;
    int lh = left->height;
    int rw = right->width;
    int rh = right->height;
    int *data = malloc(sizeof(int) * (lw * lh));

    for(int i = 0; i < lh; i++)
    {
        for(int j = 0; j < lw; j++)
        {
            data[i * rw + j] = left->ptr[i][j] - right->ptr[i][j];
        }
    }


    return mtrx_ctor(lw, lh, data);
};
Matrix* mtrx_trnspse(Matrix *m);

