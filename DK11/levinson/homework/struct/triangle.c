#include "shapes.h"

int validate_triangle(TrianglePtr t)
{
    if(t == NULL || t->pt_a == NULL || t->pt_b == NULL || t->pt_c == NULL)
    {
        return 0;
    }
    else
    {
        return 1;    
    }
}
TrianglePtr cpy_tringle(TrianglePtr source)
{
    if(source == NULL)
        return source;

    return create_triangle_PPP(source->pt_a, source->pt_b, source->pt_c);
};
TrianglePtr create_triangle_PPP(PointPtr a, PointPtr b, PointPtr c)
{
    if(a == NULL || b == NULL || c == NULL)
    {
        printf("\nNULL argument passed to create_triangle_PPP() function.\n");
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
        printf("\nNULL argument passed to create_triangle_LL() function.\n");
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
void print_triangle(TrianglePtr t)
{
    char* info = triangle_info(t);
    printf("\n%s\n", info);
};
char* triangle_info(TrianglePtr t)
{
    char* failed = "sprintf() has failed inside triangle_info() function.";

    if(!validate_triangle(t))
        return "                    NULL                   ";

    char* buffer = calloc(80, sizeof(char));
    int result = sprintf(buffer, "a(%4.1f, %4.1f), b(%4.1f, %4.1f), c(%4.1f, %4.1f)", 
    t->pt_a->x, t->pt_a->y, t->pt_b->x, t->pt_b->y, t->pt_c->x, t->pt_c->y);

    if(result)
    {
        return buffer;
    }
    else
    {
        return failed;
    }
}