#include "shapes.h"

LinePtr create_line_coord(double x_a, double y_a, double x_b, double y_b)
{
    LinePtr line = calloc(1, sizeof(Line));
    line->a = create_point(x_a, y_a);
    line->b = create_point(x_b, y_b);

    return line;
};
LinePtr create_line_pts(PointPtr a, PointPtr b)
{
    if(a == NULL || b == NULL)
    {
        printf("\nNULL argument passed to create_line_pts() function.\n");
        return NULL;
    }

    return create_line_coord(a->x, a->y, b->x, b->y);
};
void free_line(LinePtr l)
{
    if(l != NULL)
    {
        free_point(l->a);
        free_point(l->b);
        free(l);
        l = NULL;
    }
};
