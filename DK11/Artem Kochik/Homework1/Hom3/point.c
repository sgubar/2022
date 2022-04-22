#include <stdio.h>
#include <stdlib.h>
#include "point.h"
typedef struct tag_point {
int x;
int y;
} Point ;
Point *createPoint(int x, int y);
void moveToCoordinate(Point *p, int x, int y)
void deletePoint(Point +p);
void printPoint(Point *p);
Point *copyPoint(Point *p);
int isEqualPoints(Point *lp, Point *rp);
#endif /*point.h/ 
