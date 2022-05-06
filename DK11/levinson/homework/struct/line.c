#include <stdlib.h>
#include "shapes.h"
#include <math.h>

LinePtr create_line_coord(int x_a, int y_a, int x_b, int y_b)
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
