#ifndef _DK12_TOOL_H
#define _DK12_TOOL_H

typedef struct tag_point {
	double x;
	double y;
} Point;

typedef struct tag_trapezoid {
	Point *point1;
	Point *point2;
    Point *point3;
    Point *point4;
} Trapezoid;

Point *createPoint(double x, double y);

Trapezoid *createTrapezoid(Point *point1, Point *point2, Point *point3, Point *point4);
Trapezoid *createTrapezoidXY(double point1x, double point1y, double point2x, double point2y, double point3x, double point3y, double point4x, double point4y);
Trapezoid *createArrayTrapezoid(Point *array[]);

double areaTrapezoid(Trapezoid *trapezoid);
void destroyTrapezoid(Trapezoid* trapezoid);
void infoTrapezoid(Trapezoid* trapezoid, double s);

#endif