#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"

int getA(void)
{
    int x;
    printf("Введіть число A: ");
    scanf("%d", &x);
    return x;
}

int getB(void)
{
    int x;
    printf("Введіть число B: ");
    scanf("%d", &x);
    return x;
}

int getC(void)
{
    int x;
    printf("Введіть число C: ");
    scanf("%d", &x);
    return x;
}

int getSum(int a)
{
    int sum = 0;
    for(int d = 0;d <= a;d++)
    {
        sum += pow(2,d + a);
    }
    return sum;
}

double calcResult(int a,int b,int c, int sum)
{
    int up = a + b + c;
    double down = 100.0 - b - c;
    if (down == 0)
    {
        printf("Знаменник не повинен бути 0");
        exit(0);
    }
    double result = up / down + sum;
    return result;
}

void printResult(double result)
{
    printf("Результат: = %lf", result);
}#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"

int getA(void)
{
    int x;
    printf("Введіть число A: ");
    scanf("%d", &x);
    return x;
}

int getB(void)
{
    int x;
    printf("Введіть число B: ");
    scanf("%d", &x);
    return x;
}

int getC(void)
{
    int x;
    printf("Введіть число C: ");
    scanf("%d", &x);
    return x;
}

int getSum(int a)
{
    int sum = 0;
    for(int d = 0;d <= a;d++)
    {
        sum += pow(2,d + a);
    }
    return sum;
}

double calcResult(int a,int b,int c, int sum)
{
    int up = a + b + c;
    double down = 100.0 - b - c;
    if (down == 0)
    {
        printf("Знаменник не повинен бути 0");
        exit(0);
    }
    double result = up / down + sum;
    return result;
}

void printResult(double result)
{
    printf("Результат: = %lf", result);
}
