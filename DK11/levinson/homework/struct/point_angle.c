#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "shapes.h"

#pragma region Point

PointPtr create_point(double x, double y)
{
    PointPtr p = calloc(1, sizeof(Point));
    p->x = x;
    p->y = y;

    return p;
};
PointPtr cpy_point(PointPtr p)
{
    PointPtr new = calloc(1, sizeof(Point));
    new->x = p->x;
    new->y = p->y;

    return new;
};
void free_point(PointPtr p)
{
    if(p != NULL)
    {
        free(p);
        p = NULL;
    }
};
void print_point(PointPtr p)
{
    if(p != NULL)
    {
        printf("\nPoint coordinates - X: %4.3f; Y: %4.3f;\n", p->x, p->y);
    }
    else
    {
        printf("NULL pointer passed to print_point() function.");
    }
};

#pragma endregion
