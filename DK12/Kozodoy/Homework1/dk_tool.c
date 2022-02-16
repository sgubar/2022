#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"
#include <stdlib.h>

void transpose_matrix(int* t_matrix, int* matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			t_matrix[j * row + i] = matrix[i * col + j];
		}
	}
}

int* create_matrix(int row, int col)
{
	int* matrix = (int*)malloc(row * col * sizeof(int));
	return matrix;
}

void input_matrix(int* matrix, int row, int col)
{
	printf("\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("Enter [%i, %i] matrix param: ", i, j);
			scanf("%i", &matrix[i * col + j]);
		}
		printf("\n");
	}
}

void output_matrix(int* matrix, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%i ", matrix[i * col + j]);
		}
		printf("\n");
	}
}