#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dk_tool.h"

int getA()
{
    int x;
    printf("Print A:\n");
    scanf("%d", &x);

    if (x < 1 || x % 1 != 0)
    {
        printf("Number A must be integer & must be > 0 !\n");
        exit(0);
    }
    return x;
}

float getB()
{
    float x;
    printf("Print B:\n");
    scanf("%f", &x);
    return x;
}

float getC()
{
    float x;
    printf("Print C:\n");
    scanf("%f", &x);
    if (x == 0)
    {
        printf("Number C must not be 0 !\n");
        exit(0);
    }
    return x;
}

float calcNumerator(int A, float B, float C)
{
    float numerator = fabs(A * C - B);
    return numerator;
}

int calcSum(int A)
{
    float sum;
    for (int d = 0; d <= A; d++)
    {
        sum = sum + pow(2, d);
    }
    return sum;
}

void result(float numerator, float C, int sum)
{
    float result = (numerator / pow(C, 3) * sum);
    printf("Result: %f\n", result);
}
