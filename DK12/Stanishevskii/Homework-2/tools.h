#ifndef TOOLS_H
#define TOOLS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tagPoint
{
    int x;
    int y;
}Point;

typedef struct tagTriangle
{
    Point* A;
    Point* B;
    Point* C;
}RightTriangle;

RightTriangle* createRightTriangle(Point* A, Point* B, Point* C);
void destroyRightTriangle(RightTriangle* aTriangle);
int AreaOfRightTriangle(RightTriangle* aTriangle);
void PrintRightTriangle(RightTriangle* aTriangle);


#endif
