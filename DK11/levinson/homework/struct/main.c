#include <stdio.h>
#include "shapes.h"

int main(void)
{
    PointPtr origin = create_point(0, 0);
    PointPtr a = create_point(5, 0);
    PointPtr b = create_point(0, 10);
 
    LinePtr s_a = create_line_pts(a, b);
    LinePtr s_b = create_line_pts(a, origin);

    TrianglePtr trn = create_triangle_LL(s_a, s_b);

    printf("area: %f \n", calculate_triangle_area(trn));
}

