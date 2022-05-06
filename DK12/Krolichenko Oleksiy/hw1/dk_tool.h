#include <stdio.h>
#include <stdlib.h>
#define DK_TOOL_H
#ifdef DK_TOOL_H

int** createMatrix(int row, int col);
void inputMatrix1(int** m1, int row, int col);
void inputMatrix2(int** m2, int row, int col);
int** multiply(int** m2, int** m1, int row, int col);
void result(int** m1, int row, int col);
void delete_matrix(int** m, int row);

#endif // DK_TOOL_H