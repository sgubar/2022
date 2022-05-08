#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include "point.h"

typedef struct tag_square {
    Point *A;
    Point *B;
    Point *C;
    Point *D;
} Square;

int SizeofSides(Square *Square);
int inputCoords(int x);
Square *createSquareByPoints(Point *p1, Point *p2, Point *p3, Point *p4);
Square *createSquareByCoords (int x1, int x2, int y1, int y2);
void deleteSquare(Square *c);
void printSquare (Square *c);
Square *copySquare(Square *c);
int isEqualSquare(Square *lc, Square *rc);


#endif // SQUARE_H_INCLUDED
