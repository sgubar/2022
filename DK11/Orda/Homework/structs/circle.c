#include<stdio.h>
#include<stdlib.h>

#include "circle.h"

int input_coord(int a){
    int A;
    printf ("Координата точок %i = ", a);
    scanf("%d",  &A);

    return A;
}

Circle *createCircleByPoints(Point *p1, Point *p2){
    if(NULL == p1 || NULL == p2){
        return NULL;
    }
    Circle *c = (Circle *)malloc(sizeof(Circle));
    if (NULL != c) {
        c->A = copyPoint(p1);
        c->B = copyPoint(p2);
    }
    return c;
}

Circle *createCircleByCoords (int x1, int x2, int y1, int y2){
    Circle *c = (Circle *)malloc(sizeof(Circle));
    if (NULL != c) {
        c->A = createPoint(x1, y1);
        c->B = createPoint(x2, y2);
    }
    return c;
}

void printCircle(Circle *c){
    if (NULL != c){
        printPoint(c->A);
        printf("-");
        printPoint(c->B);
        printf("\n");
    }
}

double circleRadius(Circle *c){
    if (NULL == c){
        return -1;
    }
    long dx = c->A->x - c->B->x;
    long dy = c->A->y - c->B->y;
    return sqrt(dx*dx + dy*dy);
}

double circle_area(Circle *c){
    if (NULL == c){
        return -1;
    }
    long dx = c->A->x - c->B->x;
    long dy = c->A->y - c->B->y;
    long r  = sqrt(dx*dx + dy*dy);
    return 3.14*r*r;
}

void deleteCircle(Circle *c)
{
    if (NULL != c){
        deletPoint(c->A);
        deletPoint (c->B);
        free(c);
    }
}