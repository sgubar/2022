#ifndef ARRAYPOINTS_H_INCLUDED
#define ARRAYPOINTS_H_INCLUDED

#include <stdio.h>
#include "point.h"

#define ArrayPointIndexError (-1)



typedef struct tag_ArrayPoints {
   Point  **storage;
   long count;

}ArrayPoints;

ArrayPoints *createArrayPoints(long preservedCount);
void deleteArrayPoints(ArrayPoints *a);

int setPointAtIndex(ArrayPoints *a, Point *value, int index);
Point *getPointAtIndex (ArrayPoints *a, int index);

void printArrayPoints (ArrayPoints *a);
long countArrayPoints(ArrayPoints *a);

#endif // ARRAYPOINTS_H_INCLUDED
