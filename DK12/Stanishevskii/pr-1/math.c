#include <stdio.h>
#include <math.h>
#include "math.h"
#define MOD(n) (n < 0 ? -n : n)

int value(int a) // функция ввода переменных
{
    int A;
    printf("Parametr %i = ", a);
    scanf_s("%d", &A);

    return A;
}

long factorial(int number) // функция факториала 
{
    long result = 1;
    if (number < 0) {
        return -1;
    }
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}
long sum_factorial(int start, int finish, int x) // функция для сумм факториалов
{

    long result = 0;
    for (int i = start; i <= finish; i++) {
        result += factorial(x + i);
    }
    return result;
}
double q(int a, int b, int c) // сама формула 
{
    return a * sqrt(b + c) / b + (double)sum_factorial(0, c, a);
}
