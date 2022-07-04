#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "math.h"

int main()
{
    int x1 = fillcoords (1);
    int y1 = fillcoords (2);
    int x2 = fillcoords (3);
    int y2 = fillcoords (4);
    int x3 = fillcoords (5);
    int y3 = fillcoords (6);


    Point *A = createPoint(x1, y1);
    printf("Point A - ");
    printPoint(A);
    printf("\n");

    Point *B = createPoint(x2, y2);
    printf("Point B - ");
    printPoint(B);
    printf("\n");

    Point *C = createPoint(x3, y3);
    printf("Point C - ");
    printPoint(C);
    printf("\n");



    Line *l1 = createLineByPoints(A, B);
    Line *l2 = createLineByPoints(B, C);
    Line *l3 = createLineByPoints(C, A);

    printf("Line AB ");
    printLine (l1);
    printf("Line BC ");
    printLine (l2);
    printf("Line CA ");
    printLine (l3);


    float L1 = lenghtLine(l1);
    float L2 = lenghtLine(l2);
    float L3 = lenghtLine(l3);



    float hip;
    float cat1;
    float cat2;

    if (L1>L2 && L1>L3)
    {
         hip = L1;
         cat1 = L2;
         cat2 = L3;
    }
    if (L2>L1 && L2>L3)
    {
         hip = L2;
         cat1 = L1;
         cat2 = L3;
    }
    if (L3>L1 && L3>L2)
    {
         hip = L3;
         cat1 = L1;
         cat2 = L2;
    }

    if (hip*hip ==(cat1*cat1 + cat2*cat2))
    {
        printf("hipotenuse: %f\n", hip);
        printf("cat1: %f\n", cat1);
        printf("cat2: %f\n", cat2);
        float S = 0.5 * cat1 * cat2;
        printf("Area = %f\n", S);

        deleteLine(l1);
        deleteLine(l2);
        deleteLine(l3);

    }

    else
    {
        printf("it is impossible to construct a right triangle using these coordinates");

    }

}
