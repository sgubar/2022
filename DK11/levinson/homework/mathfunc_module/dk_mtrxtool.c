#include <stdlib.h>
#include "dk_mtrxtool.h"

void mtrx_dtor(Matrix *m1)
{
    if(m1 == NULL)
        return;

    free(m1->ptr[0]);
    free(m1->ptr);
    free(m1);
    m1 = NULL;
};
void mtrx_print(Matrix* m)
{
    if(m == NULL || m->ptr == NULL)
    {
        printf("\nNULL pointer or an invalid matrix passed to mtrx_print funciton!\n");
        return;
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
Matrix* mtrx_ctor(int width, int height, int *input)
{
    if(input == NULL)
    {
        printf("\nNULL pointer passed to mtrx_ctor funciton!\n");
        return NULL;
    }

    int arrlen = width * height * sizeof(int);
    int *data = malloc(arrlen);
    memcpy(data, input, arrlen);

    Matrix *result = malloc(sizeof(Matrix));
    result->ptr = malloc(sizeof(int*) * height);
    result->height = height;
    result->width = width; 

    for(int i = 0; i < height; i++)
    {
        result->ptr[i] = &data[i * width];
    }

    return result;
};
Matrix* mtrx_prod(Matrix *left, Matrix *right)
{
    if(left == NULL || right == NULL ||
    left->ptr == NULL || right->ptr == NULL)
    {
        printf("\nNULL pointer or an invalid matrix passed to mtrx_prod funciton!\n");
        return NULL;
    }

    if(left->width != right->height)
    {
        printf("\nMismatched matrices passed to mtrx_prod funciton!\n");
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
Matrix* mtrx_num_prod(Matrix* m, int mult)
{
    if(m == NULL || m->ptr == NULL)
    {
        printf("\nNULL pointer or an invalid matrix passed to mtrx_num_prod funciton!\n");
        return NULL;
    }

    Matrix *new = mtrx_ctor(m->width, m->height, m->ptr);

    for(int i = 0; i < m->height; i++)
    {
        for(int j = 0; j < m->width; j++)
        {
            new->ptr[i][j] = m->ptr[i][j] * mult;
        }
    }

    return new;
};
Matrix* mtrx_sum(Matrix *left, Matrix *right)
{
    if(left == NULL || right == NULL ||
    left->ptr == NULL || right->ptr == NULL)
    {
        printf("\nNULL pointer or an invalid matrix passed to mtrx_sum funciton!\n");
        return NULL;
    }

    if(left->width != right->width || left->height != right->height)
    {
        printf("\nMismatched matrices passed to mtrx_sum funciton!\n");
        return NULL;
    }
    
    int *data = malloc(sizeof(int) * (left->width * left->height));

    for(int i = 0; i < left->height; i++)
    {
        for(int j = 0; j < left->width; j++)
        {
            data[i * right->width + j] = left->ptr[i][j] + right->ptr[i][j];
        }
    }

    return mtrx_ctor(left->width, left->height, data);
};
Matrix* mtrx_diff(Matrix *left, Matrix *right)
{
    if(left == NULL || right == NULL ||
    left->ptr == NULL || right->ptr == NULL)
    {
        printf("\nNULL pointer or an invalid matrix passed to mtrx_diff funciton!\n");
        return NULL;
    }

    if(left->width != right->width || left->height != right->height)
    {
        printf("\nMismatched matrices passed to mtrx_diff funciton!\n");
        return NULL;
    }
    
    int *data = malloc(sizeof(int) * (left->width * left->height));

    for(int i = 0; i < left->height; i++)
    {
        for(int j = 0; j < left->width; j++)
        {
            data[i * right->width + j] = left->ptr[i][j] - right->ptr[i][j];
        }
    }


    return mtrx_ctor(left->width, left->height, data);
};
Matrix* mtrx_trnspse(Matrix *m)
{
    if(m == NULL || m->ptr == NULL)
    {
        printf("\nNULL pointer or an invalid matrix passed to mtrx_trnspse funciton!\n");
        return NULL;
    }

    int h = m->height;
    int w = m->width;
    int arrlen = h * w;
    int temp[arrlen];
    int idx = 0;

    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++)
        {
            temp[idx] = m->ptr[j][i];
            idx++;
        }
    }

    mtrx_dtor(m);

    return mtrx_ctor(h, w, temp);
};