#include <stdio.h>
#include "square.h"
#include <math.h>
#include "line.h"


int square_input_coords ( int a)
{
int A;
printf ("Coords point %i = ", a );
scanf("%d",  &A);

return A;
}

Square *createSquareByPoints(Point *p1, Point *p2, Point *p3, Point *p4)
{
    if (NULL == p1 || NULL == p2 || NULL == p3 || NULL == p4) {
        return NULL;
    }
    Square *r = (Square *)malloc(sizeof(Square));
    if (NULL != r) {
        r->A = copyPoint(p1);
        r->B = copyPoint(p2);
        r->C = copyPoint(p3);
        r->D = copyPoint(p4);
    }
    return r;
}
Square *createSquareByCoords (int x1, int x2, int y1, int y2, int x3, int y3, int x4, int y4)


{
   Square *r = (Square *)malloc(sizeof(Square));
    if (NULL != r) {
        r->A = createPoint(x1, y1);
        r->B = createPoint(x2, y2);
        r->C = createPoint(x3, y3);
        r->D = createPoint(x4, y4);

    }
    return r;

}
