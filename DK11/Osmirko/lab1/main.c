#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main()
{
   int a = input_data(1);
   int b = input_data(2);
   if(denominator(a, b) == 0)
   {
      printf("ПОМИЛКА!");
   }
   else
   {
      printf("A! = %ld\n", factorial(a));
      printf("Результат обчислення = %.5f\n", q(a, b));
      return 0;
   }
}
