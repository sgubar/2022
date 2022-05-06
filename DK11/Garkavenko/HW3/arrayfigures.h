#ifndef arrayfigures_h
#define arrayfigures_h

#define ArrayPointIndexError (-1)

#include <stdio.h>
#include <string.h>
#include "circle.h"
#include "point.h"

typedef struct tag_arrayfigures {
    Square **storage;
    long count;
}ArrayFigures;

ArrayFigures *createArrayFigures(long preservedCount);
void deleteArrayFigures(ArrayFigures *a);

int setSquareAtIndex(ArrayFigures *a, Square *value, int index);
Square *getPointAtIndex (ArrayFigures *a, int index);

void printArrayFigures(ArrayFigures *a);
long countArrayFigures(ArrayFigures *a);

long reallocateInternalStorage(ArrayFigures *a, int requestedCount);

#endif
