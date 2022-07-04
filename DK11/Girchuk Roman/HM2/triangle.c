#include <stdio.h>
#include "triangle.h"
#include <math.h>
#include "line.h"


int fillcoords (int a)
{
int X;
printf ("Coords point %i = ", a);
scanf("%d",  &X);

return X;
}

Triangle *createTriangleByPoints(Point *p1, Point *p2, Point *p3)
{
    if (NULL == p1 || NULL == p2 || NULL == p3) {
        return NULL;
    }
    Triangle *t = (Triangle *)malloc(sizeof(Triangle));
    if (NULL != t) {
        t->A = copyPoint(p1);
        t->B = copyPoint(p2);
        t->C = copyPoint(p3);
    }
    return t;
}
Triangle *createTriangleByCoords (int x1, int x2, int y1, int y2, int x3, int y3)
{
   Triangle *t = (Triangle *)malloc(sizeof(Triangle));
    if (NULL != t) {
        t->A = createPoint(x1, y1);
        t->B = createPoint(x2, y2);
        t->C = createPoint(x3, y3);

    }
    return t;

}
