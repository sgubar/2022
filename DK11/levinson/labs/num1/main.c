#include <stdlib.h>
#include <stdio.h>
#include "func.h"

float main(void)
{
    float a, b, c;
    get_values(&a, &b, &c);

    printf("\nCalculated result: %f \n", func(a, b, c));
}