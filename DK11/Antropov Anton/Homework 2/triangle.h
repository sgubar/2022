#ifndef triangle_h
#define triangle_h

#include <stdio.h>
#include "point.h"

typedef struct tag_triangle{
    Point *A;
    Point *B;
    Point *C;
}Triangle;

int inputCoords(int a);
Triangle *createTriangleByPoints(Point *p1, Point *p2, Point *p3);
Triangle *createTriangleByCoords (int x1, int x2, int x3, int y1, int y2, int y3);
void deleteTriangle(Triangle *triangle);
void printTriangle (Triangle *triangle);
Triangle *copyTriangle(Triangle *triangle);
int isEqualTriangle(Triangle *lc, Triangle *rc);
Point *centerTriangle(Triangle *triangle);

#endif
