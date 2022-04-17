#include <stdio.h>
#include "point.h"

int main()
{
    int x1 = inputCoords(1);
    int y1 = inputCoords(2);
    int x2 = inputCoords(3);
    int y2 = inputCoords(4);
    Point *p1 = createPoint(x1,y1);
    Point *p2 = createPoint(x2,y2);
    Circle *c = createCircleByPoints(p1,p2);
    printCircle(c);
    printf("radius: %f\n",radiusCircle(c));
    deleteCircle(c);
    deletePoint(p1);
    deletePoint(p2);
}
