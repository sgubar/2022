#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int input_data (int a)
{
   int A;
   printf ("num %i = ",a);
   scanf("%d", &A);

   return A;

}

long factorial (int number)
{
    long result = 1;
    if (number < 0){
        return -1;
    }
    for (int i = 1; i <= number; i++){
        result *= i;
    }
    return result;
}
long denominator (int a, int b)
{
   int denom = abs(2 * a + b);
   return denom;

}

double q(int a, int b)
{
   return (double) (factorial(a)) / (double) (denominator(a, b));
}
