#ifndef _DK12_TOOL_H
#define _DK12_TOOL_H

typedef struct tag_point
{
    double x;
    double y;
} Point;

typedef struct tag_circle
{
    Point *center;
    Point *edge_a;
    Point *edge_b;
} Elips;

Point *createPoint(double x, double y);
Elips *createElips(Point *center, Point *edge_a, Point *edge_b);
Elips *createElipsXY(double centerX, double centerY, double edge_aX, double edge_aY, double edge_bX, double edge_bY);
Elips *createArrElips(Point *array[]);

double areaElips(Elips *elips);
double hypotElips(Elips *elips);
void destroyElips(int count, Elips *arrayElips[]);
void printDetailElips(int count, Elips *arrayElips[]);

#endif