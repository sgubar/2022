#include <stdio.h>
#include <stdlib.h>
#include "point.h"

IP *createPoint(int x, int y){
      IP *point = (IP *)malloc(sizeof(IP));
      if (NULL != point)
      {
            point->x = x;
            point->y = y;
      }
      return point;
}
void delitPoint(IP *q){
      if (NULL != q)
      {
            free(q);
      }
}
void printPoint(IP *q){
      if (NULL == q)
      {
            return;
      }

      printf("(%d,%d)", q->x, q->y);
}
IP *copyPoint(IP *q)
{
      if (NULL == q)
      {
            return NULL;
      }

      return createPoint(q->x, q->y);
}