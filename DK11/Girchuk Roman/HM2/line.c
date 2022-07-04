#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "line.h"

Line *createLineByPoints(Point *p1, Point *p2)
{
    if (NULL == p1 || NULL == p2) {
        return NULL;
    }
    Line *l = (Line *)malloc(sizeof(Line));
    if (NULL != l) {
        l->A = copyPoint(p1);
        l->B = copyPoint(p2);
    }
    return l;
}
Line *createLineByCoords (int x1, int x2, int y1, int y2){
    Line *l = (Line *)malloc(sizeof(Line));
    if (NULL != l) {
        l->A = createPoint(x1, y1);
        l->B = createPoint(x2, y2);
    }
    return l;
}
void deleteLine(Line *l)
{
    if (NULL != l){
        deletePoint(l->A);
        deletePoint (l->B);
        free(l);
    }
}

void printLine (Line *l)
{
    if (NULL != l){
        printPoint(l->A);
        printf("-");
        printPoint(l->B);
        printf("\n");
    }
}
Line *copyLine(Line *l)
{
    if (NULL == l){
            return NULL;
    }
    return createLineByPoints(l->A, l->B);
}

int isEqualLine(Line *ll, Line *rl){
   if(NULL == ll || NULL == rl) {
    return 0;
   }
   return (isEqualPoint(ll->A, rl->A) && isEqualPoint(ll -> B, rl->B)) ? 1 : 0;
}

float lenghtLine(Line *l)
{

    if (NULL == l){
        return -1;
    }
    float S=l->A->x - l->B->x;
    float D=l->A->y - l->B->y;

    return sqrt(S*S+D*D);
}
