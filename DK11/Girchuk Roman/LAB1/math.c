#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math.h"
#define MOD(n) (n<0 ? -n : n)



int value (int a)// функція для вводу змінних
{
    int A;
    printf("value %i = ", a);
    scanf("%d", &A);
    return A;
}

double power (int base, int pow)
{
    double result = 1;
    for(int i=0; i<MOD(pow); i++)
    {
            result *= base;
    }
    return (pow<0) ? 1/result : result;
}

long sum_power (int start, int finish)
{
    long result = 0;
    for (int i=start; i<finish; i++)
    {
       result+=  power(2, (i + finish));
    }
    return result;
}

double q(int a, int b, int c) // функція основної формули
{

    return (double)(a + b + c) / (double)(100 - b - c) + sum_power (0, a);// не правильно рахує (a + b + c) / (100 - b - c), округляє

}
