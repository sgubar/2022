#ifndef circle_h
#define circle_h

#include "point.h"

typedef struct tag_circle {
    struct tag_point *A;
    struct tag_point *B;
} Circle;

int inputCoords(int x);
Circle *createCircleByPoints(struct tag_point *p1, struct tag_point *p2);
Circle *createCircleByCoords (int x1, int x2, int y1, int y2);
void deleteCircle(Circle *c);
void printCircle (Circle *c);
Circle *copyCircle(Circle *c);
int isEqualCircle(Circle *lc, Circle *rc);
double radiusCircle(Circle *c);

#endif
