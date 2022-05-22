#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include <math.h>
#include "point.h"

typedef struct tag_circle
{
    Point *A;
    int r;
}Circle;

int input_coord(int a);
int input_radius();

Circle *createCircleByPoints(Point *p1, int r);
Circle *createCircleByCoords (int x1, int y1, int r);
Circle *createCircle(void);

Circle *copyCircle(Circle *c);

void printCircle(Circle *c);
double circle_area(Circle *c);

void deleteCircle(Circle *c);

#endif // CIRCLE_H_INCLUDED
