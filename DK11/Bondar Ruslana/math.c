#include <stdio.h>

#include "math.h"
#define MOD(n) (n < 0 ? -n : n)


int input_data (int a)
{
int A;
printf ("Параметр %i = ",a);
scanf("%d", &A);

return A;

}

double power (int base, int pow)
{
    double result = 1;
    for ( int i = 0; i < MOD(pow); i++){
        result *= base;
    }
    return (pow < 0) ? 1.0 /result : result;

}
long sum (int start, int finish)
{
long result = 0;
for ( int i = start; i < finish; i ++){
    result += power(2, i);
}
return result;
}
double q(int a, int b, int c)
{
return MOD(a * c - b) / (double)(pow(c, 3)) * (double)sum(0, a);
}
