#ifndef DPLINE_H_INCLUDED
#define DPLINE_H_INCLUDED

#include <stdio.h>
#include "arraypoints.h"

typedef struct tag_DPLine {
   ArrayPoints *points;
}DPLine;

DPLine *createDPLineByPoints(Point *p1, Point *p2);
DPLine *createDPLineByCoords(int x1, int y1, int x2, int y2);
DPLine *createDPLine(void);

void deleteDPLine(DPLine *l);
int countPoints(DPLine *l);

void addPointToDPLine(DPLine *l, Point *p);
void addPointByXYToDPLine(DPLine *l, int x, int y);
void deleteLastPointFromDPLine(DPLine *l);

void printDPLine(DPLine *l);
DPLine *copyDPLine(DPLine *l);
int isEqualDPLine(DPLine *ll, DPLine *rl);

double lenghtDPLine(DPLine *l);

#endif // DPLINE_H_INCLUDED
