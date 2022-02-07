#ifndef DK_MTRXTOOL
#define DK_MTRXTOOL

typedef struct Matrix
{
    // ptr provides a convinient way to interface with the Matrix (e.g. m[row][column])
    // also, (ptr == NULL) indicates that a function returnig Matrix type did not execute properly (e.g. when addition of differently sized matrices is attempted)
    int **ptr;
    int height;
    int width;
    // hdata is the pointer to the actual memory location of the values for this Matrix
    // int *hdata;
} Matrix;

void mtrx_dtor(Matrix);
Matrix mtrx_ctor(int width, int height, int values[width*height]);
Matrix mtrx_prod(Matrix, Matrix);
Matrix mtrx_num_prod(Matrix, int);
Matrix mtrx_sum(Matrix,Matrix);
Matrix mtrx_diff(Matrix,Matrix);
Matrix mtrx_trnspse(Matrix);

#endif