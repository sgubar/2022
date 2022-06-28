#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "point.h"

typedef struct tag_rectangle {
    Point *A;
    Point *B;
    Point *C;
    Point *D;
} Rectangle;

int SizeofSides(Rectangle *Rectangle);

Rectangle *createRectangleByPoints(Point *p1, Point *p2, Point *p3, Point *p4);
Rectangle *createRectangleByCoords (int x1, int x2, int y1, int y2);
void deleteRectangle(Rectangle *c);
void printRectangle (Rectangle*c);
Rectangle *copyRectangle(Rectangle *c);
int isEqualRectangle(Rectangle *lc, Rectangle *rc);

#endif // RECTANGLE_H_INCLUDED
