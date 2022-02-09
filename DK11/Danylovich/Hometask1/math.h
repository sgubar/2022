#ifndef math_h
#define math_h

#include <stdlib.h>
#include <stdio.h>

int **create_matrix(int row, int col);
void printarray(int **matrix,int n);
void delete_matrix(int **matrix, int row);

#endif 
