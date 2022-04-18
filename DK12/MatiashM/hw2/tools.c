#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "tools.h"

Point *create_point(double x, double y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (point != NULL)
    {
        point->x = x;
        point->y = y;
    }
    return point;
}

Square *create_square(Point *point1, Point *point2)
{
    Square *square = (Square *)malloc(sizeof(Square));
    if (square != NULL)
    {
        square->point1 = point1;
        square->point2 = point2;
    }
    return square;
}

Square *create_squareXY(double point1x, double point1y, double point2x, double point2y)
{
    Point *point1 = create_point(point1x, point1y);
    Point *point2 = create_point(point2x, point2y);
    Square *square = create_square(point1, point2);
    return square;
}

Square *create_arr_square(Point *array[])
{
    Square *array_square = create_square(*array, (*array + 1));
    return array_square;
}

double area_square(Square *square)
{
    double area;
    if (square != NULL)
    {
        area = pow(hypot((square->point1->x-square->point2->x), (square->point1->y-square->point2->y)),2);
    }
    return area;
}

void square_destroy(Square *square)
{
    free(square->point1);
    free(square->point2);
    free(square);
}

void square_info(Square *square, double area)
{
    printf("\n\nFirst point: x = %lf; y = %lf\n", square->point1->x, square->point1->y);
    printf("Second point: x = %lf; y = %lf\n", square->point2->x, square->point2->y);
    printf("Area: %lf\n\n", area);
}