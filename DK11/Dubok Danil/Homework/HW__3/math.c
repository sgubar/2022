#include <stdlib.h>
#include <stdio.h>

float fact(int base1){
      float res = 1;
      if (base1 == 0)
      {
            res = 1;
      }
      else
      {
            for (int x = base1; x > 0; x--)
            {
                  res *= x;
            }
      }
      return (base1 < 0) ? -1 : res;
}

float mod(int base2)
{
      float re;
      if (base2 >= 0)
      {
            re = base2;
      }
      else
      {
            re = -base2;
      }
      return re ;
}

//хоча це й не універсальна фунція, але я її запишу

void result(int a, int b)
{
      int s = (2 * a + b);
      if (mod(s) == 0, a > 10, a < 0, fact(a) == -1)
      {
            printf("error\n");
      }
      else{
      printf("Результат: %.2f", fact(a) / mod(s));
      }
 }