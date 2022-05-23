#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>
#include "math.h"

int main(int argc, const char * argv[])
{
    int a= dimensions();
    int b= dimensions();
    int **matrix = create_matrix(a,b);
    fillarray((int **)matrix,a,b);
    printf("Матриця\n");
    printarray((int **)matrix,a,b);
    transmat((int **)matrix,a,b);
    printf("Транспонована Матриця\n");
    printarray((int **)matrix,a,b);
    delete_matrix((int **)matrix,a);
    return 0;
}
