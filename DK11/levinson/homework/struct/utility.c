#include <stdlib.h>
#include <math.h>
#include "shapes.h"

PointPtr project_onto_line(PointPtr p, LinePtr l)
{
    if(line_isnull(l))
        return NULL;
        
    double slope = line_slope(l);
    double yintercept = line_yintercept(l, slope);
    double ortho_slope = pow(slope, -1) * -1;
    double ortho_yintercept = p->y - ortho_slope * p->x;

    double intersect_x = (ortho_yintercept - yintercept)/(slope - ortho_slope);
    double intersect_y = slope * intersect_x + yintercept;

    return create_point(intersect_x, intersect_y);
};
int line_isnull(LinePtr line)
{
    if(line == NULL || line->a == NULL || line->b == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};
int triangle_isnull(TrianglePtr tr)
{
    if(tr == NULL || tr->pt_a == NULL || tr->pt_b == NULL || tr->pt_c == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
};