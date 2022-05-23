#include <stdio.h>
#include <stdlib.h>
#include "point.h"

Point *createPoint(int x,int y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if(point != NULL){
        point->x = x;
        point->y = y;
    }
return point;
}

void deletePoint(Point *p)
{
    if(p != NULL){
        free(p);
    }
}


void printPoint(Point *p)
{
    if(p == NULL){
        return;
    }

    printf("(%d,%d)",p->x,p->y);
}


Point *copyPoint(Point *p)
{
    if(p == NULL){
        return NULL;
    }

    return createPoint(p->x,p->y);
}


int isEqualPoints(Point *lp,Point *rp)
{
    if(lp == NULL || rp == NULL){
        return 0;
    }

    return (lp == rp || (lp->x == rp->x && lp->y == rp->y)) ? 1 : 0;
}
