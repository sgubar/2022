#include "arraysquare.h"
#include <stdlib.h>
#include <string.h>
#define SquareArrayIndexError
typedef struct tag_point {
    double x;
    double y;
} Point;

typedef struct tag_square {
     Point *A;
    Point *B;
    Point *C;
    Point *D;
} Square;


typedef struct tag_squareArray {
    Square  **storage;
    int count;
} SquareArray;
int square_input_coords ( int a);
Point *createPoint(double x, double y);
Square *createSquareByPoints(Point *p1, Point *p2, Point *p3, Point *p4);
Square *createSquareByCoords (int x1, int x2, int y1, int y2, int x3, int y3, int x4, int y4);
Square *createArrSquare(Point *array[]);
SquareArray *createSquareArray(int count);
ArraySquare *createArraySquare(long preservedCount);
void deleteArraySquare(ArraySquare *a);
int setSquareAtIndex(ArraySquare *a, Square *value, int index);
Square *getSquareAtIndex (ArraySquare *a, int index);
void printArraySquare (ArraySquare *a);
long countArraySquare(ArraySquare *a);



#endif
