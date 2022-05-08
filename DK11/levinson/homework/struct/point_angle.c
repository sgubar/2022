#include <stdlib.h>
#include <math.h>
#include "shapes.h"

#pragma region Angle
AnglePtr create_angle_deg(double deg)
{
    AnglePtr a = calloc(1, sizeof(Angle));

    int rotations = (int)deg / 360;
    a->degrees = deg;
    a->rad = 2 * M_PI * ((deg - rotations * 360)/360.0);

    return a;
};
AnglePtr create_angle_rad(double rad)
{
    AnglePtr a = calloc(1, sizeof(Angle));

    double rad_pi = rad/M_PI;
    int rotations = (int)(rad_pi) / 2;

    a->degrees = ((rad_pi - 2 * M_PI * rotations) * 180);
    a->rad = rad;

    return a;
};
AnglePtr cpy_angle(AnglePtr angle)
{
    AnglePtr a = calloc(1, sizeof(Angle));
    a->degrees = angle->degrees;
    a->rad = angle->rad;

    return a;
}
void free_angle(AnglePtr a)
{
    if(a != NULL)
    {
        free(a);
    }
}

#pragma endregion
#pragma region Point

PointPtr create_point(double x, double y)
{
    PointPtr p = calloc(1, sizeof(Point));
    p->x = x;
    p->y = y;

    return p;
};
PointPtr project_onto_line(PointPtr p, LinePtr l)
{
    double slope = line_slope(l);
    double yintercept = line_yintercept(l, slope);
    double ortho_slope = pow(slope, -1) * -1;
    double ortho_yintercept = p->y - ortho_slope * p->x;

    double intersect_x = (ortho_yintercept - yintercept)/(slope - ortho_slope);
    double intersect_y = slope * intersect_x + yintercept;

    return create_point(intersect_x, intersect_y);
};
PointPtr cpy_point(PointPtr p)
{
    PointPtr new = calloc(1, sizeof(Point));
    new->x = p->x;
    new->y = p->y;

    return new;
};
void free_point(PointPtr p)
{
    if(p != NULL)
    {
        free(p);
    }
};
void print_point(PointPtr p)
{
    if(p != NULL)
    {
        printf("\nPoint coordinates - X: %4.3f; Y: %4.3f;\n", p->x, p->y);
    }
};

#pragma endregion
