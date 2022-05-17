#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"

Circle *create(Point *center , int rad)
{
    Circle *Result = NULL;
    if (center != NULL && rad > 0)
    {
        Result = (Circle *)malloc(sizeof(Circle));
        if (NULL != Result)
        {
            Result->center = copyPointWithPoint(center);
            Result->rad = rad;
        }
    }
    return Result;
}

Circle *create2(int x, int y, int rad)
{
    Point *center = NULL;
    center = (Point *)malloc(sizeof(Point));
    if (NULL != center)
    {
        center->x=x;
        center->y=y;
    }
    return create(center , rad);
}

void printCircle(Circle *circle)
{
    int rad = circle->rad, x = circle->center->x, y = circle->center->y;
    printf("x: %d\ny: %d\nРадіус: %d\nПлоща = %.5f\n", rad, x, y, area(circle));
}

void destroy(Circle *aCircle)
{
    if (NULL != aCircle)
    {
        free(aCircle->center);
        free(aCircle);
    }
}

Point *copyPointWithPoint(Point *aPoint)
{
    Point *Result = (Point *)malloc(sizeof(Point));
    if (NULL != Result)
    {
        Result->x = aPoint->x;
        Result->y = aPoint->y;
    }
    return Result;
}

float area(Circle *circle)
{
    float area = pi * pow(circle->rad, 2);
    return area;
}
