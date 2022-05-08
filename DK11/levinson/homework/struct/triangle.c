#include <stdio.h>
#include "shapes.h"

TrianglePtr create_triangle_PPP(PointPtr a, PointPtr b, PointPtr c)
{
    if(a == NULL || b == NULL || c == NULL)
    {
        printf("\nNULL argument passed to create_LL() function.\n");
        return NULL;
    }

    TrianglePtr trn = calloc(1, sizeof(Triangle));
    trn->pt_a = cpy_point(a);
    trn->pt_b = cpy_point(b);
    trn->pt_c = cpy_point(c);
    
    return trn;
};
TrianglePtr create_triangle_PArr(Point pts[3])
{
    return create_triangle_PPP(&pts[0], &pts[1], &pts[2]);
}
TrianglePtr create_triangle_LL(LinePtr a, LinePtr b)
{
    if(line_isnull(a) || line_isnull(b))
    {
        printf("\nNULL argument passed to create_LL() function.\n");
        return NULL;
    }

    if(points_equal(a->a, b->a) || points_equal(a->a, b->b))
    {
        return create_triangle_PPP(a->b, b->a, b->b);
    }
    else if (points_equal(a->b, b->a) || points_equal(a->b, b->b))
    {
        return create_triangle_PPP(a->a, b->a, b->b);
    }
    else
    {
        printf("\nGiven lines do not form a triangle!\n");
        return NULL;
    }
};
void free_triangle(TrianglePtr t)
{
    if(t != NULL)
    {
        free_point(t->pt_a);
        free_point(t->pt_b);
        free_point(t->pt_c);
        free(t);
        t = NULL;
    }
};