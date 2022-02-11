#include <stdio.h>
#include "dk_tool.c"

int main()
{
    int n = 0;
	printf("Введіть розмір матриць для множення: ");
	scanf("%d", &n);
	int arr1[n*n], arr2[n*n], arr3[n*n];
	
	for(int i = 0; i < n*n ; i++)
	{
		printf("\n Введіть %d число першої матриці: ", i+1);
		scanf("%d", &arr1[i]);
	}
	
		for(int i = 0; i < n*n ; i++)
		{
			printf("\n Введіть %d число другої матриці: ", i+1);
			scanf("%d", &arr2[i]);
		}
		
			matrix1(n, arr1);
			matrix2(n, arr2);
			matrix3(n, arr1, arr2, arr3);
		    
}

