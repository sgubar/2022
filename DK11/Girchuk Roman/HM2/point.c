#include <stdio.h>
#include <stdlib.h>
#include "point.h"

Point *createPoint(int x, int y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (NULL != point){
        point ->x = x;
        point ->y = y;
    }
    return point;
}

void deletePoint (Point *p){
   if (NULL != p){
    free (p);
   }
}

void printPoint (Point *p)
{
    if (NULL == p) {
        return;
    }
    printf("(%d, %d)", p->x, p->y);
}

Point *copyPoint(Point *p){
   if (NULL == p) {
    return NULL;
   }
   return createPoint(p->x, p->y);
}

int isEqualPoint (Point *lp, Point *rp){
    if (NULL == lp || NULL == rp ){
    return 0;
}
 return (lp == rp || (lp -> x == rp -> x && lp -> y == rp -> y)) ? 1 : 0;
}
