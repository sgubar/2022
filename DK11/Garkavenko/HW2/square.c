#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "square.h"
#include "point.h"

int inputCoords(int x)
{
    printf("Введіть %i число: ",x);
    scanf("%d",&x);
    return x;
}

Square *createSquareByPoints(Point *p1, Point *p2, Point *p3, Point *p4)
{
    if (NULL == p1 || NULL == p2) {
        return NULL;
    }
    Square *square = (Square *)malloc(sizeof(Square));
    if (NULL != square) {
        square->A = copyPoint(p1);
        square->B = copyPoint(p2);
        square->C = copyPoint(p3);
        square->D = copyPoint(p4);
    }
    return square;
}
Square *createSquareByCoords (int x1, int x2, int y1, int y2){
    Square *square = (Square *)malloc(sizeof(Square));
    if (NULL != square) {
        square->A = createPoint(x1, y1);
        square->B = createPoint(x2, y2);
    }
    return square;
}
void deleteSquare(Square *c)
{
    if (NULL != c){
        deletePoint(c->A);
        deletePoint (c->B);
        free(c);
    }
}

void printSquare(Square *c)
{
    if (NULL != c){
        printPoint(c->A);
        printf("-");
        printPoint(c->B);
        printf("\n");
    }
}
Square *copySquare(Square *c)
{
    if (NULL == c){
            return NULL;
    }
    return createSquareByPoints(c->A, c->B,c->C, c->D);
}
int SizeofSides(Square *Square)
{
    int x1 = Square->A->x;
    int y1 = Square->A->y;

    int x2 = Square->B->x;
    int y2 = Square->B->y;

    int x3 = Square->C->x;
    int y3 = Square->C->y;

    int x4 = Square->D->x;
    int y4 = Square->D->y;

    int a =(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    int b =(x4-x1)*(x4-x1)+(y4-y1)*(y4-y1);
    int c =(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
    int d =(x3-x4)*(x3-x4)+(y3-y4)*(y3-y4);
if (a==b && a == c && a == d)
    {
        return 1;
    }else
    return 0;
}

int isEqualSquare(Square *lc, Square *rc){
   if(NULL == lc || NULL == rc) {
    return 0;
   }
   return (isEqualPoints(lc->A, rc->A) && isEqualPoints(lc -> B, rc->B)) ? 1 : 0;

}
