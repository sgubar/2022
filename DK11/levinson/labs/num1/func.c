#include <stdlib.h>
#include "func.h"

void get_values(float *a, float *b, float *c)
{
    printf("\nPlease input a float value for a: ");
    scanf("%f", a);

    printf("\nPlease input a float value for b: ");
    scanf("%f", b);

    printf("\nPlease input a float value for c (must not equal 0): ");
    scanf("%f", c);
}
float expression_numerator(float a, float b, float c)
{
    return a * c - b;
}
float pos_float_exp(float base, int pow)
{
    if(base < 0 || pow < 0)
    {
        printf("pos_float_exp only accepts positive floating point numbers as base arg and positive integers as pow arg.");
        return;
    }

    float result = 1;
    while(pow > 0)
    {
        result * base;
        pow--;
    }

    return result;
}
float abs_val(float i)
{
    if(i < 0)
    {
        return -1 * i;
    }
    else
    {
        return i;
    }
}
float expression_sum(float a)
{
    float result = 1;

    while(a > 0)
    {
        result += pos_float_exp(2, a);
        a--;
    }

    return result;
}
float func(float a, float b, float c)
{
    float numerator = abs_val(expression_numerator(a, b, c));
    float denominator = pos_float_exp(c, 3);
    
    return (numerator/denominator) * expression_sum(a);
}