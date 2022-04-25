#include <stdio.h>
#include <string.h>
#include "point.h"
#include "circle.h"
#include "arrayfigures.h"

int main()
{
    int x1 = inputCoords(1);
    int y1 = inputCoords(2);
    int x2 = inputCoords(3);
    int y2 = inputCoords(4);
    Point *p1 = createPoint(x1,y1);
    Point *p2 = createPoint(x2,y2);
    Circle *c = createCircleByPoints(p1,p2);
    printf("\nLoading Circle...\n\n");
    printCircle(c);
    printf("radius: %f\n",radiusCircle(c));
    printf("\nLoading Array of Figures...\n\n");
    ArrayFigures *a = createArrayFigures(4);
    printArrayFigures(a);

    setCircleAtIndex(a,c,0);
    printArrayFigures(a);

    setCircleAtIndex(a,c,4);
    printArrayFigures(a);
    
    deletePoint(p1);
    deletePoint(p2);
    deleteCircle(c);
    deleteArrayFigures(a);
}
