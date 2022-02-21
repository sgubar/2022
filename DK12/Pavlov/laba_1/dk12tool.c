#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "dk12tool.h"

int enter(float *a, float *b, float *c)
{
   printf("Enter a:");
   scanf("%f", &*a);
   printf("Enter c:");
   scanf("%f", &*c);
   printf("Enter b:");
   scanf("%f", &*b);
   int newb = ceil(*b);
   if (*b - newb != 0)
   {
     printf("FATAL ERROR, B MUST BE INTEGER");
     return 0;
   }
   return 1;

}
int factorial(float fac)
{
  return (fac < 2) ? 1 : fac * factorial (fac - 1);
}

float sum(float b)
{
  int data = 0;
  for(int d = 0; d<=b; d++)
    {
        data += factorial(d);
    }
    return data;
}


float calc(float a, float b, float c)
{
    float x;
    if (enter(&a, &b, &c) == 1)
    {
      x = (a*b)/(b + pow(c,2)) + sum(b);
      return x;
    }
    else 
    {
      return -1;
    }
}
