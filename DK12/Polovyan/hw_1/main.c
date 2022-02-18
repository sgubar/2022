#include <stdio.h>
#include "dk_tool.c"

int main()
{
    int n = get_N();
	int arr1[n*n], arr2[n*n], arr3[n*n];
	
	arr1[n*n] = get_matrix1(n, arr1);
	arr2[n*n] = get_matrix2(n, arr2);
		
	matrix1(n, arr1);
	matrix2(n, arr2);
	matrix3(n, arr1, arr2, arr3);		    
}

