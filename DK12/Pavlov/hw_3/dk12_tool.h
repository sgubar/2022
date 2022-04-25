#ifndef _DK12_TOOL_H
#define _DK12_TOOL_H
#define TrapezoidArrayIndexError (-1)

typedef struct tag_point {
	double x;
	double y;
} Point;

typedef struct tag_trapezoid {
	Point *point1;
	Point *point2;

    Point *point3;
    Point *point4;
} Trapezoid;

typedef struct tag_trapezoidArray {
    Trapezoid  **storage;
    int count;
} TrapezoidArray;

Point *createPoint(double x, double y);

Trapezoid *createTrapezoid(Point *point1, Point *point2, Point *point3, Point *point4);
Trapezoid *createTrapezoidXY(double point1x, double point1y, double point2x, double point2y, double point3x, double point3y, double point4x, double point4y);
Trapezoid *createArrayTrapezoid(Point *array[]);

void printDetailTrapezoid(Trapezoid *trapezoid);

TrapezoidArray *createTrapezoidArray(int count);

int addTrapezoidToArray(TrapezoidArray *array, Trapezoid *trapezoid);
int setTrapezoidAtIndex(TrapezoidArray *array, Trapezoid *trapezoid, int index);

Trapezoid *getTrapezoidAtIndex (TrapezoidArray *array, int index);

int countTrapezoidArray(TrapezoidArray *array);
void printTrapezoidArray(TrapezoidArray *array);
void deleteTrapezoidArray(TrapezoidArray *array);

#endif