#include "math.h"

int **create_matrix(int row, int col)
{
	int **matrix = (int **)malloc(sizeof(int *) * row); // int *array[];

	for (int i = 0; i < row; i++) {
		*(matrix + i) = (int *)malloc(sizeof(int) * col); //void *
	}

	return matrix;
}

void delete_matrix(int **matrix, int row) {
	if (matrix == NULL) {
		return;
	}

	for (int i = 0; i < row; i++) {
		free (*(matrix + i));
	}

	free(matrix);
}

void printarray(int **matrix,int n)
{
    int i=0,j=0;
    while(i<n)
    {
        j=0;
        while(j<3)
        {
            printf("%d\t", *(*(matrix + i) + j));
            j++;
        }
    i++;
    printf("\n");
    }
}
