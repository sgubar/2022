#ifndef line_h
#define line_h
#include <stdio.h>
#include "point.h"
#define MAX_POINTS 128
typedef struct tag_PolyLine {
    Point *points[MAX_POINTS];
    int count;
}PolyLine;

PolyLine *createLineByPoints(Point *p1, Point *p2);
PolyLine *createLineByCoords(int x1, int y1, int x2, int y2);
PolyLine *createLine(void);

void deleteLine(PolyLine *1);
int countPoints(PolyLine *1);

void addPoint (PolyLine *1, Point *p);
void deleteLastPoint(PolyLine *1);
void printLine(PolyLine *1);

PolyLine *copyLine(PolyLine *1);
int isEqualLine(PolyLine *l1, PolyLine *r1);

double lenghtLine(PolyLine *1);
#endif /*line_h*/
