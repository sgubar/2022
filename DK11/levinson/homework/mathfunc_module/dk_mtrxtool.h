#ifndef DK_MTRXTOOL
#define DK_MTRXTOOL

typedef struct Matrix
{
    int **ptr;
    int height;
    int width;
} Matrix;

void mtrx_dtor(Matrix);
Matrix mtrx_ctor(int width, int height, int* values);
Matrix mtrx_prod(Matrix, Matrix);
Matrix mtrx_num_prod(Matrix, int);
Matrix mtrx_sum(Matrix,Matrix);
Matrix mtrx_diff(Matrix,Matrix);
Matrix mtrx_trnspse(Matrix);

#endif