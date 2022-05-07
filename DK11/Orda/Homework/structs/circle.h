#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <math.h>
#include "point.h"

typedef struct tag_circle
{
    Point *A;
    Point *B;
}Circle;

int input_coord(int a);
Circle *createCircleByPoints(Point *p1, Point *p2);
Circle *createCircleByCoords (int x1, int x2, int y1, int y2);

void printCircle(Circle *c);
double circleRadius(Circle *c);
double circle_area(Circle *c);

void deleteCircle(Circle *c);

#endif