#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dk12tool.h"

float a, b, c;
float data = 0;

int enter(void)
{
   printf("Enter a:");
   scanf("%f", &a);
   printf("Enter c:");
   scanf("%f", &c);
   printf("Enter b:");
   scanf("%f", &b);
   if (b % 1 != 0)
   {
       printf("!FATAL ERROR! \nEnter b as integer value");
       return 0;
   }
   
}

int factorial(float fac)
{
  return (fac < 2) ? 1 : fac * factorial (fac - 1);
}

float calc()
{   
    float x;
    enter();
    for(int d = 0; d<=b; d++)
    {
        data += factorial(d);
    }
    x = (a*b)/(b + pow(c,2)) + data;
    return x;
}
