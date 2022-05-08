#include <stdio.h>
#include "shapes.h"

int main(void)
{
    PointPtr origin = create_point(0, 0);
    PointPtr a = create_point(6, 0);
    PointPtr b = create_point(0, 4);

    LinePtr line = create_line_pts(a, b);

    print_point(project_onto_line(origin, line));
    // printf("length: %f \n", line_length(line));
}

