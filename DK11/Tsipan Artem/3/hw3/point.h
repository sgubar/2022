#ifndef point_h
#define point_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point{
    int x;
    int y;
}Point;

Point *createPoint(int x,int y);
void deletePoint(Point *p);
void printPoint(Point *p);
Point *copyPoint(Point *p);
int isEqualPoints(Point *lp,Point *rp);

#endif 
