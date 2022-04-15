#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "point.h"

typedef struct tag_line
{
    Point *A;
    Point *B;
}Line;

Line *createLine(Point *p1, Point *p2);
void deletLine(Line *l);
void printLine(Line *l);
Line *copyLine(Line *l);
double lenghtLine(Line *l);
double circleArea(Line *l);

#endif