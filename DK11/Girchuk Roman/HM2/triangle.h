#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "point.h"

typedef struct tag_Triangle {
    Point *A;
    Point *B;
    Point *C;
    Point *D;
} Triangle;

int fillcoords (int a);

Triangle *createTriangleByPoints(Point *p1, Point *p2, Point *p3);
Triangle *createTriangleByCoords (int x1, int x2, int y1, int y2, int x3, int y3);
#endif // TRIANGLE_H_INCLUDED
