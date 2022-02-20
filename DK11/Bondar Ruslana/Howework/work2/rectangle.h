#define RECTANGLE_H_INCLUDED

#include "point.h"

typedef struct tag_Rectan {
    Point *A;
    Point *B;
    Point *C;
    Point *D;
} Rectan;


int rectan_input_coords ( int a);
Rectan *createRectanByPoints(Point *p1, Point *p2, Point *p3, Point *p4);
Rectan *createRectanByCoords (int x1, int x2, int y1, int y2, int x3, int y3, int x4, int y4);




#endif // RECTANGLE_H_INCLUDED
