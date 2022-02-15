#include <stdio.h>
#include <math.h>

#include "dk_tool.h"

void input_size() {
	printf("Enter the size of the matrix, example: 4 3\n");
	scanf_s("%d%d", &row, &col);
}

void input_value() {
	printf("enter the number that is multiplied by the matrix: \n");
	scanf_s("%d", &num);

	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			printf("Enter the value [%i][%i] of the matrix number: \n", r, c);
			scanf_s("%d", &matrix[r][c]);
		}
	}
}

void count() {
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			matrix[r][c] = matrix[r][c] * num;
		}
	}
}

void output_matrix() {
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++) {
			printf("%i ", matrix[r][c]);
		}
		printf("\n");
	}
}