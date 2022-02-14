#include "math.h"

int dimensions()
{
    int a;
    printf("Введіть розмір матриці: \n");
    scanf("%d",&a);
    return a;
}

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

void printarray(int **matrix,int a,int b)
{
    int i=0,j=0;
    while(i<a)
    {
        j=0;
        while(j<b)
        {
            printf("%d\t", *(*(matrix + i) + j));
            j++;
        }
    i++;
    printf("\n");
    }
}

void transmat(int **matrix,int a,int b)
{
    int n=0, m=0;

    while(n<a-1)
    {
        m=0;
        while(m<b)
        {
            if(n==1 && m==0)
            {
                m++;
            }else{
            int k = *(*(matrix + n) + m);
            *(*(matrix + n) + m) = *(*(matrix + m) + n);
            *(*(matrix + m) + n) = k;
            m++;
            }
        }
    n++;
    }
}

void fillarray(int **matrix,int a,int b)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            *(*(matrix + i) + j) = get_int("a[%d][%d]=",i,j);
        }
    }
}
