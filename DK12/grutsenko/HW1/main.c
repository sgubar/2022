#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dk_tool.h"
#include "cs50.h"

int main(int argc, char* argv[])
{   
    if (arg_check(argc, *argv[1])) {
        exit(EXIT_FAILURE);
    }
    
    int a = atoi(argv[1]);

    matrix m1 = make_matrix(a, a);
    matrix m2 = make_matrix(a, a);
    matrix m3 = make_matrix(a, a);

    matrix* pM1 = &m1;
    matrix* pM2 = &m2;
    matrix* pM3 = &m3;

    enter_matrix(pM1, "matrix1");
    enter_matrix(pM2, "matrix2");

    multiply_matrix(pM1, pM2, pM3);

    print_matrix(pM3);

    return 0;
}