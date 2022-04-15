#define square

#include "point.h"

typedef struct tag_Square {
    Point *A;
    Point *B;
    Point *C;
    Point *D;
} Square;


int square_input_coords ( int a);
Square *createSquareByPoints(Point *p1, Point *p2, Point *p3, Point *p4);
Square *createSquareByCoords (int x1, int x2, int y1, int y2, int x3, int y3, int x4, int y4);




#endif
