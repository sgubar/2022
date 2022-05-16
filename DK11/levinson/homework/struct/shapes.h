#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

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
void print_line(LinePtr l);
void free_line(LinePtr l);

#pragma endregion
#pragma region Triangle

typedef struct Triangle
{
    PointPtr pt_a;
    PointPtr pt_b;
    PointPtr pt_c;
} Triangle, *TrianglePtr;

TrianglePtr create_triangle_PPP(PointPtr a, PointPtr b, PointPtr c);
TrianglePtr create_triangle_PArr(Point pts[3]);
TrianglePtr create_triangle_LL(LinePtr a, LinePtr b);
TrianglePtr cpy_tringle(TrianglePtr source);
void print_triangle(TrianglePtr t);
char* triangle_info(TrianglePtr t);
void free_triangle(TrianglePtr t);

#pragma endregion
#pragma region Utility

int points_equal(PointPtr a, PointPtr b);
int line_isnull(LinePtr line);
int triangle_isnull(TrianglePtr tr);
PointPtr project_onto_line(PointPtr p, LinePtr l);
double line_length(LinePtr line);
double line_slope(LinePtr line);
double line_yintercept(LinePtr line, double slope);
double calculate_triangle_area(TrianglePtr t);

#pragma endregion