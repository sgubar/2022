#include <stdlib.h>

#pragma region PointAngle

typedef struct Angle
{
    double degrees;
    double rad;
} Angle, *AnglePtr;

AnglePtr create_angle_deg(double deg);
AnglePtr create_angle_rad(double rad);
AnglePtr cpy_angle(AnglePtr angle);
void free_angle(AnglePtr);

typedef struct Point
{   
    double x;
    double y;
} Point, *PointPtr;

PointPtr create_point(double x, double y);
PointPtr cpy_point(PointPtr p);
void free_point(PointPtr p);
void print_point(PointPtr p);

#pragma endregion
#pragma region Line

typedef struct Line
{
    PointPtr a;
    PointPtr b;
} Line, *LinePtr;

LinePtr create_line_coord(double x_a, double y_a, double x_b, double y_b);
LinePtr create_line_pts(PointPtr a, PointPtr b);
double line_length(LinePtr line);
double line_slope(LinePtr line);
double line_yintercept(LinePtr line, double slope);

#pragma endregion
#pragma region Triangle

typedef struct Triangle
{
    PointPtr pt_a;
    PointPtr pt_b;
    PointPtr pt_c;
} Triangle, *TrianglePtr;

TrianglePtr create_PPP(PointPtr a, PointPtr b, PointPtr c);
TrianglePtr create_LL(LinePtr a, LinePtr b);
TrianglePtr create_AAL(AnglePtr a, AnglePtr b, LinePtr l);

#pragma endregion
#pragma region Utility

PointPtr project_onto_line(PointPtr p, LinePtr l);

#pragma endregion