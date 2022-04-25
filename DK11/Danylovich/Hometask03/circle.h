#ifndef circle_h
#define circle_h

#include <stdio.h>
#include "point.h"

typedef struct tag_circle {
    Point *A;
    Point *B;
} Circle;

int inputCoords(int x);
Circle *createCircleByPoints(Point *p1, Point *p2);
Circle *createCircleByCoords (int x1, int x2, int y1, int y2);
void deleteCircle(Circle *c);
void printCircle (Circle *c);
Circle *copyCircle(Circle *c);
int isEqualCircle(Circle *lc, Circle *rc);
double radiusCircle(Circle *c);

#endif
