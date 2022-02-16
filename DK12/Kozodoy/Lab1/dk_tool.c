#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"
#include <stdlib.h>

void input_param(float* a, float* b, float* c)
{
    printf("Enter A > 0: ");
    scanf("%f", a);

    printf("Enter B > 0: ");
    scanf("%f", b);

    printf("Enter C > 0: ");
    scanf("%f", c);
}

float pow(float num, int pow)
{
    float result = 1;

    if (num < 0 || pow < 0)
    {
        printf("Error, you entered param < 0!\n");
        return 0;
    }

    while (pow > 0)
    {
        result *= num;
        pow--;
    }

    return result;
}

int factorial(int num)
{
    int result = 1;

    if (num < 0)
    {
        return 0;
    }

    for (size_t i = 1; i <= num; i++)
    {
        result *= i;
    }
    return result;
}

float qfunc(float a, float b, float c)
{
    float result = (((pow(a, 2) + pow(b, 2)) / (b + pow(5, c))) + factorial(b));
    return result;
}
