#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14

typedef struct tag_point
{
    int x, y;
} Point;

typedef struct tag_circle
{
    Point *center;
    int rad;
} Circle;

Circle *create(Point *center , int rad);
Circle *create2(int x, int y, int rad);
void printCircle(Circle *circle);
void destroy(Circle *aCircle);
Point *copyPointWithPoint(Point *aPoint);
float area(Circle *circle);

#endif
