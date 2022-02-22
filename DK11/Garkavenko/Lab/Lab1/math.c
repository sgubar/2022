#include <stdio.h>
#include <math.h>
#include "math.h"
#define MOD(n) (n < 0 ? -n : n)

int value (int a) // ф-ція вводу змінних
{
int A;
printf ("Параметр %i = ",a);
scanf("%d", &A);

return A;
}

long factorial(int number) //ф-ція для знаходження факторіалу 
{
    long result = 1;
    if (number < 0){
        return -1;
    }
    for (int i = 1; i <= number; i ++){
    result *= i;
    }
    return result;
}
long sum_factorial (int start, int finish, int x) //ф-ція для знаходження суми факторіалів
{

long result = 0;
for ( int i = start; i <= finish; i ++){
    result += factorial(x + i);
}
return result;
}
double q(int a, int b, int c) // ф-ція основної формули 
{
return a * sqrt(b + c) / b + (double)sum_factorial(0, c, a );
}
