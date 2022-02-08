#ifndef DK_MTRXTOOL
#define DK_MTRXTOOL

typedef struct Matrix
{
    // ptr provides a convinient way to interface with the Matrix (e.g. m[row][column])
    // if we consider that a 2d array flattens to 1d in memory, 
    // we'll find that ptr[0] points to the starting point of the memory region allocated for Matrix data
    // also, (ptr == NULL) indicates that a function returnig Matrix type did not execute properly 
    // (e.g. when an operation on mismatched matrices is attempted)
    int **ptr;
    int height;
    int width;
} Matrix;

void mtrx_dtor(Matrix*);
void mtrx_print(Matrix*);
Matrix* mtrx_ctor(int width, int height, int *data);
Matrix* mtrx_prod(Matrix*, Matrix*);
Matrix* mtrx_num_prod(Matrix*, int);
Matrix* mtrx_sum(Matrix*, Matrix*);
Matrix* mtrx_diff(Matrix*, Matrix*);
Matrix* mtrx_trnspse(Matrix*);

#endif