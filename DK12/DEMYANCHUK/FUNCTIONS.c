#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "dk_tool.h"

int main(int argc, const char* argv[]) {

    int row, colls;

    printf("%s", "Enter number of row: ");    scanf("%d", &row);
    printf("%s", "Enter number of colls: ");  scanf("%d\n", &colls);

    int** matrix_1 = NULL;
    int** matrix_2 = NULL;
    int** matrix_3 = NULL;
    
    // creating and filling first matrix
    create_matrix(&matrix_1, row, colls);
    fill_matrix(matrix_1, row, colls);
    print_matrix(matrix_1, row, colls);

    // creating and filling second matrix  
    create_matrix(&matrix_2, row, colls);
    fill_matrix(matrix_2, row, colls);
    print_matrix(matrix_2, row, colls);
    
    // creating third matrix
    create_matrix(&matrix_3, row, colls);
    
    // fraction: matrix_3 = matrix_1 - matrix_2
    fraction(matrix_1, matrix_2, matrix_3, row, colls);
    
    // answer
    print_matrix(matrix_3, row, colls); printf("\n");
        
    //del matrix_1, matrix_2, matrix_3
    del_matrix(&matrix_1, colls);
    del_matrix(&matrix_2, colls);
    del_matrix(&matrix_3, colls);
   
    return 0;
}