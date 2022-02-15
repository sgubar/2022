#include <stdio.h>
#include <math.h>
#include "dk_tools.h"

double get_A()
{
    printf("Enter A (any number):\n");
    double a;
    if(scanf("%lf", &a) < 1)
    {
        for(int c; c != EOF && c != '\n'; c = getchar());
        return get_A();
    }
    return a;
}

int get_B()
{
    printf("Enter B (integer greater than 0):\n");
    int b;
    if(scanf("%i", &b) < 1)
    {
        for(int c; c != EOF && c != '\n'; c = getchar());
        return get_B();
    }
    if(b < 1) return get_B();
    return b;
}

double get_C()
{
    printf("Enter C (any number):\n");
    double c;
    if(scanf("%lf", &c) < 1)
    {
        for(int c; c != EOF && c != '\n'; c = getchar());
        return get_C();
    }
    return c;
}

int main()
{
    double a = get_A();
    int b = get_B();
    double c = get_C();
    printf("Result: %f", (a * a + b * b) / (b + pow(5, c)) + fact(b));
    return 0;
}
