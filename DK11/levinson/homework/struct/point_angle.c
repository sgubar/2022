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
        a = NULL;
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
        p = NULL;
    }
};
void print_point(PointPtr p)
{
    if(p != NULL)
    {
        printf("\nPoint coordinates - X: %4.3f; Y: %4.3f;\n", p->x, p->y);
    }
    else
    {
        printf("NULL pointer passed to print_point() function.");
    }
};

#pragma endregion
