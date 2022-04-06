#include <stdio.h>
#include <math.h>
#include "tools.h"

int get_A(void)
{
    int a;
    printf("Type number A: ");
    scanf("%d", &a);
    return a;
}

int get_B(void)
{
    int b;
    printf("Type number B: ");
    scanf("%d", &b);
    return b;
}

int get_C(void)
{
    int c;
    printf("Type number C: ");
    scanf("%d", &c);
    return c;
}

int get_sum(int a)
{
    int num = 0;
    for(int d=0;d<=a;d++)
    {
        num += pow(2,d+a);
    }
    return num;
}

double result(int a,int b,int c, int sum)
{
    int top = a+b+c;
    double bot = 100.00-b-c;
    if (bot==0)
    {
        printf("Denominator can't be 0");
        return 0;
    }
    double res = top/bot+sum;
    return res;
}

void print_result(double res)
{
    printf("Result: (A+B+C)/(100-B-C)+∑ a,d=0 (2^(d+a))= %lf", res);
}