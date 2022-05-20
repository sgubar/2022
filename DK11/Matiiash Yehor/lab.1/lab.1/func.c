#include "func.h"


unsigned int valid_value_a()
{
    double a;
    do
    {
        printf("ENTER WHOLE A (greater or equal 0): ");
        scanf("%lf", &a);
    }
    while ((int)a != a || a < 0);
    return a;
}

double valid_value_b()
{
    double b;
        do 
        {
            printf("ENTER B (less or greater then 0): ");
            scanf("%lf", &b);
        }
        while(b == 0);
}

unsigned  int valid_value_c()
{
    double c;
    do
    {
        printf("ENTER NATURAL C: ");
        scanf("%lf", &c);
    }
    while((int)c != c || c < 0);  
    return c;
}

unsigned long int factorial(int base)
{
    unsigned long int res = 1;
    for (int i = 1; i <= base; i++)
        res *= i;
    return res;
}

unsigned  int amount_factorials(int a, int finish)
{
    unsigned  int res_of_sum = 0;
    for(int d = 0; d <= finish; d++)
        res_of_sum += factorial(a+d);
    return res_of_sum;
}

double q(unsigned int a, double b, unsigned int c)
{
    double res = a * (sqrt(b + c)/b) + amount_factorials(a, c);
    return res; 
}
