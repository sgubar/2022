#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "triangle.h"

int inputCoords(int a)
{
    printf("Введіть %i число: ",a);
    scanf("%d",&a);

    return a;
}

Triangle *createTriangleByPoints(Point *p1, Point *p2, Point *p3)
{
    if (p1 == NULL || p2 == NULL || p3 == NULL) {
        return NULL;
    }

    Triangle *triangle = (Triangle *)malloc(sizeof(Triangle));

    if (triangle != NULL) {
        triangle->A = copyPoint(p1);
        triangle->B = copyPoint(p2);
        triangle->C = copyPoint(p3);
    }

    return triangle;
}

Triangle *createtriangleByCoords (int x1, int x2, int x3, int y1, int y2, int y3){

    Triangle *triangle = (Triangle *)malloc(sizeof(Triangle));

    if (NULL != triangle) {
        triangle->A = createPoint(x1, y1);
        triangle->B = createPoint(x2, y2);
        triangle->C = createPoint(x3, y3);
    }

    return triangle;
}

void deleteTriangle(Triangle *triangle)
{
    if (triangle != NULL) {
        deletePoint(triangle->A);
        deletePoint(triangle->B);
        deletePoint(triangle->C);
        free(triangle);
    }
}

void printTriangle(Triangle *triangle)
{
    if (NULL != triangle) {
        printPoint(triangle->A);
        printf("-");
        printPoint(triangle->B);
        printf("-");
        printPoint(triangle->C);
        printf("\n");
    }
}
Triangle *copyTriangle(Triangle *triangle)
{
    if (triangle == NULL) {
        return NULL;
    }

    return createTriangleByPoints(triangle->A, triangle->B, triangle->C);
}

int isEqualTriangles(Triangle *lc, Triangle *rc){
   
   if(NULL == lc || NULL == rc) {
    return 0;
   }

   return (isEqualPoints(lc->A, rc->A) && isEqualPoints(lc -> B, rc->B)) ? 1 : 0;
}

Point *centerTriangle(Triangle *triangle)
{
    
    long X = (triangle->A->x + triangle->B->x + triangle->C->x)/ 3;
    long Y = (triangle->A->y + triangle->B->y + triangle->C->y)/ 3;

    Point *center = createPoint(X,Y);

    return center;
}
