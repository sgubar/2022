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
    if(a == NULL || b == NULL)
    {
        printf("\nNULL argument passed to create_line_pts() function.\n");
        return NULL;
    }

    LinePtr line = calloc(1, sizeof(Line));
    line->a = a;
    line->b = b;

    return line;
};
void free_line(LinePtr l)
{
    if(l != NULL)
    {
        free_point(l->a);
        free_point(l->b);
        free(l);
    }
};
double line_length(LinePtr line)
{
    if(line_isnull(line))
    {
        printf("\nNULL argument passed to line_length() function.\n");
        return -1;
    }
        
    double x_proj = line->a->x - line->b->x;
    double y_proj = line->a->y - line->b->y;

    return sqrt(pow(x_proj, 2) + pow(y_proj, 2));
};
double line_slope(LinePtr line)
{
    if(line_isnull(line))
    {
        printf("\nNULL argument passed to line_slope() function.\n");
        return -1;
    }
        
    return (line->b->y - line->a->y)/(line->b->x - line->a->x);
}
double line_yintercept(LinePtr line, double slope)
{
    if(line_isnull(line))
    {
        printf("\nNULL argument passed to line_yintercept() function.\n");
        return -1;
    }
        
    return line->a->y - line->a->x * slope;
}