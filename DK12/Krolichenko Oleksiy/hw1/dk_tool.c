#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <ctype.h>
#include "dk_tool.h"


int** createMatrix(int row, int col) {
	int** m1 = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++) {
		*(m1 + i) = (int*)malloc(sizeof(int*) * col);
	}
	return m1;
}

void inputMatrix1(int** m1, int row, int col) {
	printf("ћатриц€ 1 \n\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("¬вед≥ть значенн€ [%d][%d] ", i + 1, j + 1);
			scanf(" %d", &*(*(m1 + i) + j));
		}
	}
	printf("\n");
}

void inputMatrix2(int** m2, int row, int col) {
	printf("ћатриц€ 2 \n\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("¬вед≥ть значенн€ [%d][%d] ", i + 1, j + 1);
			scanf(" %d", &*(*(m2 + i) + j));
		}
	}
	printf("\n");
}

int** multiply(int** m2, int** m1, int row, int col) {
	int** mult = createMatrix(row, col);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(*(mult + i) + j) = 0;
			for (int a = 0; a < row; a++) {
				*(*(mult + i) + j) += *(*(m1 + i) + a) * *(*(m2 + a) + j);
			}
		}
	}
	return mult;
}

void result(int** m1, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %d", *(*(m1 + i) + j));
		}
		printf("\n");
	}
}