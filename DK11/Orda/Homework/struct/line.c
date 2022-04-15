#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "line.h"
#include "point.h"

Line *createLine(Point *p1, Point *p2){
    if (NULL == p1 || NULL == p2){
        return 0;
    }
    Line *l = (Line *)malloc(sizeof(Line));
    if (NULL != l)
    {
        l->A = copyPoint(p1);
        l->B = copyPoint(p2);
    }
    return l;
}

void deletLine(Line *l){
    if (NULL != l){
        deletPoint(l->A);
        deletPoint(l->B);
        free(l);
    }
}

void printLine(Line *l){
    if (NULL != l){
        printPoint(l->A);
        printf("-");
        printPoint(l->B);
        printf("\n");
    }
}

double lenghtLine(Line *l){
    if (NULL == l){
        return -1;
    }
    long dx = l->A->x - l->B->x;
    long dy = l->A->y - l->B->y;
    return sqrt(dx*dx + dy*dy);
}

double circleArea(Line *l){
    if (NULL == l){
        return -1;
    }
    long dx = l->A->x - l->B->x;
    long dy = l->A->y - l->B->y;
    long r  = sqrt(dx*dx + dy*dy);
    return 3.14*r*r;
}