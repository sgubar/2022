#ifndef dk_tool_h
#define dk_tool_h

#include <stdio.h>

int* create_matrix(int row, int col);
void transpose_matrix(int* t_matrix, int* matrix, int row, int col);
void input_matrix(int* matrix, int row, int col);
void output_matrix(int* matrix, int row, int col);
#endif // !1