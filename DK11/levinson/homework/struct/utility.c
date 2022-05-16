#include "shapes.h"

int points_equal(PointPtr a, PointPtr b)
{
    if(a->x == b->x && a->y == b->y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
double calculate_triangle_area(TrianglePtr t)
 {
    if(triangle_isnull(t))
    {
        printf("\nNULL argument passed to calculate_area() function.\n");
        return -1;
    }

    LinePtr base = create_line_pts(t->pt_a, t->pt_b);
    PointPtr h = project_onto_line(t->pt_c, base);
    LinePtr height = create_line_pts(t->pt_c, h);
    double area = line_length(height) * line_length(base) / 2;

    free_point(h);
    free_line(base);
    free_line(height);

    return area;
};