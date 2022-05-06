#include <stdio.h>
#include <string.h>
#include "point.h"
#include "square.h"
#include "arrayfigures.h"

int main()
{
    int x1 = inputCoords(1);
    int y1 = inputCoords(2);
    int x2 = inputCoords(3);
    int y2 = inputCoords(4);
    int x3 = inputCoords(5);
    int y3 = inputCoords(6);
    int x4 = inputCoords(7);
    int y4 = inputCoords(8);

    Point *p1 = createPoint(x1,y1);
    Point *p2 = createPoint(x2,y2);
    Point *p3 = createPoint(x3,y3);
    Point *p4 = createPoint(x4,y4);
    Square *c = createSquareByPoints(p1,p2,p3,p4);
if (SizeofSides(c)==1)
    {
    printf("\n Please wait, loading Square...\n\n");
    printSquare(c);
    printf("\nLoading Array of Figures...\n\n");
    ArrayFigures *a = createArrayFigures(4);
    printArrayFigures(a);

    setSquareAtIndex(a,c,0);
    printArrayFigures(a);

    setSquareAtIndex(a,c,4);
    printArrayFigures(a);
    deleteSquare(c);

    deletePoint(p1);
    deletePoint(p2);
    deletePoint(p3);
    deletePoint(p4);
    deleteArrayFigures(a);
    }else
printf("Error");
}
