#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "array_rectangle.h"
#include "rectangle.h"

int main()
{
    int x1 = 2;
    int y1 = 1;
    int x2 = 2;
    int y2 = 4;
    int x3 = 7;
    int y3 = 4;
    int x4 = 7;
    int y4 = 1;

    Point *p1 = createPoint(x1,y1);
    Point *p2 = createPoint(x2,y2);
    Point *p3 = createPoint(x3,y3);
    Point *p4 = createPoint(x4,y4);
    Rectangle *c = createRectangleByPoints(p1,p2,p3,p4);

    if (SizeofSides(c)==1)
    {
    printf("\n Rectangle: \n\n");
    printRectangle(c);
    printf("\n Array of Rectangle: \n\n");
    ArrayRectangle *a = createArrayRectangle(4);
    printArrayRectangle(a);

    setRectangleAtIndex(a,c,0);
    printArrayRectangle(a);

    setRectangleAtIndex(a,c,4);
    printArrayRectangle(a);
    deleteRectangle(c);

    deletePoint(p1);
    deletePoint(p2);
    deletePoint(p3);
    deletePoint(p4);
    deleteArrayRectangle(a);
    }else{
printf("Please enter the correct coordinates\n");
}
    printf("Hello world!\n");
    return 0;
}
