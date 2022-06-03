#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"
#include "trap.h"
#include "math.h"

IT *createTrap(IP *p1, IP *p2, IP *p3, IP *p4){
      if (NULL == p1 || p2 == NULL || p3 == NULL || p4 == NULL){
            return 0;
      }
      IT *t = (IT *)malloc(sizeof(IT));
      if (t != 0)
      {
            t->A = copyPoint(p1);
            t->B = copyPoint(p2);
            t->C = copyPoint(p3);
            t->D = copyPoint(p4);
      }
      return t;
}
void delitTrap(IT *t){
      if (abs((t->A->y) - (t->C->y)) != abs((t->B->y) - (t->D->y)) || abs(t->A->x - t->C->x) == abs(t->B->x - t->D->x))
      {
            printf("Це не трапеція, притримуйтесь правил!");
      }
      delitPoint(t->A);
      delitPoint(t->B);
      delitPoint(t->C);
      delitPoint(t->D);
}
void printTrap(IT *t){
      if(t != NULL){
            printPoint(t->A);
            printf("-");
            printPoint(t->B);
            printf("-");
            printPoint(t->C);
            printf("-");
            printPoint(t->D);
            printf("\n");
      }
}

float S(IT *t){
      float S = 0;
      int h = mod((t->C->y) - (t->A->y));
      int a = mod((t->A->x) - (t->B->x));
      int b = mod((t->C->x) - (t->D->x));
      S = ((a + b) / 2) * h;
      return S;
}
 int inputC(char a, char b){
       printf("Введіть координату %c, точки %c  ",b,a);
       int x;
       scanf("%d", &x);
       return x;
 }
 
 void help(){
       printf("Це програма для підрахунку площі фігури що складається з трапецій\nДля продовження натисніть 0+Enter\nДля видоду довідки натисніть 1+Eter \n");
       int help;
       scanf("%d", &help);
       if (help == 1)
       {
             printf("Є декілька умов коректної роботи програми:\n 1)Ввід має здійснюватися послідовно(спочатку точки основи А і В, після чого точки основи С і D)\n 2)|yA - yC| має дорівнювати |yB - yD| (для паралельності основ)\n 3)|xА - xС| не має дорівнювати |xB - xD| (для непаралельності бічних сторін)(окрім рівнобічних трапецій де (xА - xС) = -(xВ - xD)\n");
       }
 }

 IT *copyTrap(IT *q)
 {
       if (NULL == q)
       {
             return NULL;
       }

       return createTrap(q->A, q->B, q->C, q->D);
 }