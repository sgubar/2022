#include <stdlib.h>
#include "func.h"

void get_values(int *a, float *b, float *c)
{
    printf("\nPlease input a float value for a: ");
    scanf("%i", a);

    printf("\nPlease input a float value for b: ");
    scanf("%f", b);

    printf("\nPlease input a float value for c (must not equal 0): ");
    scanf("%f", c);
}
float pos_float_exp(float base, int pow)
{
    if(pow < 0)
    {
        float result = 1;
        while(pow < 0)
        {
            result * base;
            pow++;
        }
        return 1/result;
    }
    else
    {
        float result = 1;
        while(pow > 0)
        {
            result * base;
            pow--;
        }
        return result;
    }
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
float expression_sum(int a)
{
    float result = 0;

    while(a > 0)
    {
        result += pos_float_exp(2, a);
        a--;
    }
    while(a < 0)
    {
        result += pos_float_exp(2, a);
        a++;
    }

    return result;
}
float func(float a, float b, float c)
{
    float numerator = abs_val(a * c - b);
    float denominator = pos_float_exp(c, 3);
    
    return (numerator/denominator) * expression_sum(a);
}