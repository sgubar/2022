#ifndef math_h
#define math_h

#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>

int dimensions();
int **create_matrix(int row, int col);
void printarray(int **matrix,int a,int b);
void delete_matrix(int **matrix, int row);
void transmat(int **matrix,int a,int b);
void fillarray(int **matrix,int a,int b);

#endif 
