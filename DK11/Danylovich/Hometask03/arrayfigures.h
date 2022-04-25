#ifndef arrayfigures_h
#define arrayfigures_h

#define ArrayPointIndexError (-1)

#include <stdio.h>
#include <string.h>
#include "circle.h"
#include "point.h"

typedef struct tag_arrayfigures {
    Circle **storage;
    long count;
}ArrayFigures;

ArrayFigures *createArrayFigures(long preservedCount);
void deleteArrayFigures(ArrayFigures *a);

int setCircleAtIndex(ArrayFigures *a, Circle *value, int index);
Circle *getPointAtIndex (ArrayFigures *a, int index);

void printArrayFigures(ArrayFigures *a);
long countArrayFigures(ArrayFigures *a);

long reallocateInternalStorage(ArrayFigures *a, int requestedCount);

#endif 
