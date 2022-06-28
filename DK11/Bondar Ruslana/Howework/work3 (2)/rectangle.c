#include "rectangle.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"


int SizeofSides(Rectangle *Rectangle);

Rectangle *createRectangleByPoints(Point *p1, Point *p2, Point *p3, Point *p4)
{
    if (NULL == p1 || NULL == p2) {
        return NULL;
    }
   Rectangle *rectangle = (Rectangle *)malloc(sizeof(Rectangle));
    if (NULL != rectangle) {
        rectangle->A = copyPoint(p1);
        rectangle->B = copyPoint(p2);
        rectangle->C = copyPoint(p3);
        rectangle->D = copyPoint(p4);
    }
    return rectangle;
}
 Rectangle *createRectangleByCoords (int x1, int x2, int y1, int y2){
     Rectangle *rectangle = ( Rectangle *)malloc(sizeof( Rectangle));
    if (NULL != rectangle) {
        rectangle->A = createPoint(x1, y1);
        rectangle->B = createPoint(x2, y2);
    }
    return rectangle;
}
void deleteRectangle(Rectangle *c)
{
    if (NULL != c){
        deletePoint(c->A);
        deletePoint (c->B);
        free(c);
    }
}
void printRectangle(Rectangle *c)
{
    if (NULL != c){
        printPoint(c->A);
        printf("-");
        printPoint(c->B);
        printf("\n");
        printPoint(c->C);
        printf("-");
        printPoint(c->D);
        printf("\n");
    }
}
Rectangle *copyRectangle(Rectangle*c)
{
    if (NULL == c){
            return NULL;
    }
    return createRectangleByPoints(c->A, c->B,c->C, c->D);
}
int SizeofSides(Rectangle *Rectangle)
{
    int x1 = Rectangle->A->x;
    int y1 = Rectangle->A->y;

    int x2 = Rectangle->B->x;
    int y2 = Rectangle->B->y;

    int x3 = Rectangle->C->x;
    int y3 = Rectangle->C->y;

    int x4 = Rectangle->D->x;
    int y4 = Rectangle->D->y;

    int a =(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    int b =(x4-x1)*(x4-x1)+(y4-y1)*(y4-y1);
    int c =(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
    int d =(x3-x4)*(x3-x4)+(y3-y4)*(y3-y4);
if (a==d && b == c)
    {
        return 1;
    }else
    return 0;
}

int isEqualRectangle(Rectangle *lc, Rectangle *rc){
   if(NULL == lc || NULL == rc) {
    return 0;
   }
   return (isEqualPoint(lc->A, rc->A) && isEqualPoint(lc -> B, rc->B)) ? 1 : 0;

}
