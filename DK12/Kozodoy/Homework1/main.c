#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main()
{

	int row = 0, col = 0;

	printf("Enter matrix row count: ");
	scanf("%i", &row);
	printf("Enter matrix col count: ");
	scanf("%i", &col);

	int* mtrx = create_matrix(row, col);
	int* tmtrx = create_matrix(col, row);

	input_matrix(mtrx, row, col);
	printf("Your matrix:\n");
	output_matrix(mtrx, row, col);

	printf("\nTranspose matrix:\n");
	transpose_matrix(tmtrx, mtrx, row, col);
	output_matrix(tmtrx, col, row);

	free(mtrx);
	free(tmtrx);

	return 0;
}