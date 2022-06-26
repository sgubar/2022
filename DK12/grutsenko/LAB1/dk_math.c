#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "dk_math.h"
#include "cs50.h"

double abs_extend(double a)
{
    if(a < 0)
    return -a;
    else return a;
}

double sigma_sum(int a, int b)
{
    double res = 0;
    for(int a; a <= b; a++) {
        res += pow(2, a);     
    }
    return res;
}
