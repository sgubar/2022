#ifndef ARRAY_RECTANGLE_H_INCLUDED
#define ARRAY_RECTANGLE_H_INCLUDED

#define ArrayPointIndexError (-1)

#include <stdio.h>
#include <string.h>
#include "point.h"
#include "rectangle.h"

typedef struct tag_arrayRectangle {
    Rectangle **storage;
    long count;
}ArrayRectangle;

ArrayRectangle *createArrayRectangle(long preservedCount);
void deleteArrayRectangle(ArrayRectangle *a);

int setRectangleAtIndex(ArrayRectangle *a, Rectangle *value, int index);
Rectangle *getPointAtIndex (ArrayRectangle *a, int index);

void printArrayRectangle(ArrayRectangle *a);
long countArrayRectangle(ArrayRectangle *a);

long reallocateInternalStorage(ArrayRectangle *a, int requestedCount);


#endif // ARRAY_RECTANGLE_H_INCLUDED
