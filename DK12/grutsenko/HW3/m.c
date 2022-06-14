#include "m.h"

double abs_extend(double a)
{
    if(a < 0)
    return -a;
    else return a;
}

double sigma_sum(int a, int b, double expression)
{
    double res = 0;
    for(int a; a <= b; a++) {
        res += expression;     
    }
    return res;
}