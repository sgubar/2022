#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"
#include "point.h"

int inputCoords(int x)
{
    printf("Введіть %i число: ",x);
    scanf("%d",&x);
    return x;
}

Circle *createCircleByPoints(Point *p1, Point *p2)
{
    if (NULL == p1 || NULL == p2) {
        return NULL;
    }
    Circle *circle = (Circle *)malloc(sizeof(Circle));
    if (NULL != circle) {
        circle->A = copyPoint(p1);
        circle->B = copyPoint(p2);
    }
    return circle;
}
Circle *createcircleByCoords (int x1, int x2, int y1, int y2){
    Circle *circle = (Circle *)malloc(sizeof(Circle));
    if (NULL != circle) {
        circle->A = createPoint(x1, y1);
        circle->B = createPoint(x2, y2);
    }
    return circle;
}
void deleteCircle(Circle *c)
{
    if (NULL != c){
        deletePoint(c->A);
        deletePoint (c->B);
        free(c);
    }
}

void printCircle(Circle *c)
{
    if (NULL != c){
        printPoint(c->A);
        printf("-");
        printPoint(c->B);
        printf("\n");
    }
}
Circle *copyCircle(Circle *c)
{
    if (NULL == c){
            return NULL;
    }
    return createCircleByPoints(c->A, c->B);
}
int isEqualCircles(Circle *lc, Circle *rc){
   if(NULL == lc || NULL == rc) {
    return 0;
   }
   return (isEqualPoints(lc->A, rc->A) && isEqualPoints(lc -> B, rc->B)) ? 1 : 0;
}

double radiusCircle(Circle *c)
{

    if (NULL == c){
        return -1;
    }
    long dX = c->B->x - c->A->x;
    long dY = c->B->y - c->A->y;

    return sqrt((dX*dX) + (dY*dY));
}
