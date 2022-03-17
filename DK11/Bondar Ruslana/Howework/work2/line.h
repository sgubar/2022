#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <stdio.h>
#include "point.h"

typedef struct tag_line {
    Point *A;
    Point *B;
} Line;

Line *createLineByPoints(Point *p1, Point *p2);
Line *createLineByCoords (int x1, int x2, int y1, int y2);
void deleteLine(Line *l);

void printLine (Line *l);
Line *copyLine(Line *l);
int isEqualLine(Line *ll, Line *rl);

double lenghtLine(Line *l);


#endif // LINE_H_INCLUDED
