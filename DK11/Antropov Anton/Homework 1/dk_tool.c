#include "dk_tool.h"

int **create_matrix(int a, int b)
{
	int **array = (int **)malloc(sizeof(int *) * a); // int *array[];

	for (int i = 0; i < a; i++) {
		*(array + i) = (int *)malloc(sizeof(int) * b); //void *
	}

	return array;
}

void delete_matrix(int **array, int a) 
{
	if (array == NULL) {
		return;
	}

	for (int i = 0; i < a; i++) {
		free (*(array + i));
	}

	free(array);
}

void fillarray(int **array,int a,int b,int c)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            *(*(array + i) + j) = get_int("a[%d][%d]=",i,j);
            *(*(array + i) + j) *= c;
        }
    }
}

void printarray(int **array,int a,int b)
{
    int i=0,j=0;
    while(i<a)
    {
        j=0;
        while(j<b)
        {
            printf("%d\t", *(*(array + i) + j));
            j++;
        }
    i++;
    printf("\n");
    }
}
