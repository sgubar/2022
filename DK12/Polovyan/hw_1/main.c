#include <stdio.h>
#include "dk_tool.c"

int main()
{
    int n = get_N(); //n*n - matrix size
	int arr3[n*n], arr2[n*n], arr1[n*n];
	
	arr1[n*n] = get_matrix1(n, arr1);
	arr2[n*n] = get_matrix2(n, arr2);
		
	print_matrix1(n, arr1);
	print_matrix2(n, arr2);
	print_matrix3(n, arr1, arr2, arr3);
		    
}

