#include <stdio.h>
#include "shapes.h"

TrianglePtr create_PPP(PointPtr a, PointPtr b, PointPtr c)
{
    if(a == NULL || b == NULL || c == NULL)
    {
        printf("\nNULL argument passed to create_LL() function.\n");
        return NULL;
    }

    TrianglePtr trn = calloc(1, sizeof(Triangle));
    trn->pt_a = a;
    trn->pt_b = b;
    trn->pt_c = c;
    
    return trn;
};
TrianglePtr create_LL(LinePtr a, LinePtr b)
{
    if(line_isnull(a) || line_isnull(b))
    {
        printf("\nNULL argument passed to create_LL() function.\n");
        return NULL;
    }

    if(a->a == b->a || a->b == b->a)
    {
        return create_PPP(a->a, a->b, b->b);
    }
    else if (a->a == b->b || a->b == b->b)
    {
        return create_PPP(a->a, a->b, b->a);
    }
    else
    {
        printf("\nGiven lines do not form a triangle!\n");
        return NULL;
    }
};
double calculate_area(TrianglePtr t)
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