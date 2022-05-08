#include <stdlib.h>
#include <math.h>
#include "shapes.h"

LinePtr create_line_coord(double x_a, double y_a, double x_b, double y_b)
{
    PointPtr a = create_point(x_a, y_a);
    PointPtr b = create_point(x_b, y_b);

    return create_line_pts(a, b);
};
LinePtr create_line_pts(PointPtr a, PointPtr b)
{
    LinePtr line = calloc(1, sizeof(Line));

    line->a = a;
    line->b = b;
    return line;
};
double line_length(LinePtr line)
{
    double x_proj = line->a->x - line->b->x;
    double y_proj = line->a->y - line->b->y;

    return sqrt(pow(x_proj, 2) + pow(y_proj, 2));
};
double line_slope(LinePtr line)
{
    return (line->b->y - line->a->y)/(line->b->x - line->a->x);
}
double line_yintercept(LinePtr line, double slope)
{
    return line->a->y - line->a->x * slope;
}