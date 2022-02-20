#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"
#include "rectangle.h"

int main()
{

    int x1=rectan_input_coords (1);
    int y1=rectan_input_coords (2);
    int x2=rectan_input_coords (3);
    int y2=rectan_input_coords (4);
    int x3=rectan_input_coords (5);
    int y3=rectan_input_coords (6);
    int x4=rectan_input_coords (7);
    int y4=rectan_input_coords (8);

    if (x1==x3 && y1==y2 && x2==x4 && y3==y4)

    {


    Point *p = createPoint( x1, y1);
    printPoint(p);
    printf("-");
    Point *copy = copyPoint(p);
    copy->x = x2;
    copy->y = y2;
    printPoint(copy);
    printf("\n");


    Point *copy1 = copyPoint (p);
    copy1 ->x = x3;
    copy1 ->y = y3;
    printPoint(copy1);
    printf ("-");
    Point *copy2 = copyPoint (p);
    copy2 ->x = x4;
    copy2 ->y = y4;
    printPoint(copy2);
    printf("\n");

    Line *l = createLineByCoords ( x1,  x2,  y1,  y2);
    Line *l2 = createLineByCoords ( x1,  x3,  y1,  y3);
    printf(" len1: %f", lenghtLine(l));
    printf(" len1: %f\n", lenghtLine(l2));

    printf(" Area = %f\n", lenghtLine(l) * lenghtLine(l2));


    deletePoint(p);
    }else{
    printf("It is impossible to create a rectangle with these coordinates");

    }

}
