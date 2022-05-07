#include <stdio.h>
#include <math.h>

#include "point.h"
#include "circle.h"

int main(){
    int x1 = input_coord(1);
    int y1 = input_coord(2);
    int x2 = input_coord(3);
    int y2 = input_coord(4);

    Point *p1 = createPoint(x1, y1);
    Point *p2 = createPoint(x2, y2);

    Circle *c = createCircleByPoints(p1, p2);

    printCircle(c);
    printf("Радіус кола: %0.2f\n", circleRadius(c));
    printf("Площа кола: %0.2f\n", circle_area(c));

    deleteCircle(c);
    deletPoint(p1);
    deletPoint(p2);
}