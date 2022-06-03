#ifndef ArrayOfCircles_h
#define ArrayOfCircles_h

#define ArrayPointIndexError (-1)

#include <stdio.h>
#include <string.h>
#include "circle.h"
#include "point.h"

typedef struct arrayOfCircles{
    Circle **storage;
    long count;
}ArrayOfCircles;

ArrayOfCircles *createArrayOfCircles(long preservedCount);
void deleteArrayOfCircles(ArrayOfCircles *a);

int setCircleAtIndex(ArrayOfCircles *a, Circle *value, int index);
Circle *getPointAtIndex (ArrayOfCircles *a, int index);

void printArrayOfCircles(ArrayOfCircles *a);
long countArrayOfCircles(ArrayOfCircles *a);

long reallocateInternalStorage(ArrayOfCircles *a, int requestedCount);

#endif 
