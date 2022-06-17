#include <stdio.h>
#include <math.h>
#include "dk12_tool.h"

int factorial(float fac)
{
    if (fac < 2)
        return 1;
    return fac * factorial(fac - 1);
}

float summ(float b)
{
    int data = 0;
    for (int i = 0; i <= b; i++)
    {
        data += factorial(i);
    }
    return data;
}

void calc(float a, float b, float c)
{
    float x;

    x = (a * b) / (b + pow(c, 2)) + summ(b);
    printf("Результат дорівнює : %.3f", x);
}

float getA()
{
    float a;
    printf("Введіть змінну A : ");
    scanf("%f", &a);
    return a;
}
float getB()
{
    float b;
    printf("Введіть змінну B : ");
    scanf("%f", &b);
    return b;
}
float getC()
{
    float c;
    printf("Введіть змінну C : ");
    scanf("%f", &c);
    return c;
}