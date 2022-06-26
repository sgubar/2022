#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dk_math.h"
#include "cs50.h"

int main()
{
    double B, C, Q = 0;
    int A, D = 0;
    printf("Enter elements. Numbers only.\n[A] must be numerical.\n[C] can't be 0\n");
    do {
        A = get_int("A: ");
    } while (A < 0);
    B = get_double("B: ");
    do {
        C = get_double("C: ");
    } while (C == 0);
    
    Q = (abs_extend(A*C-B) / pow(C, 3)) * sigma_sum(D, A);

    printf("Q = %lf\n", Q);

    return 0;
}
