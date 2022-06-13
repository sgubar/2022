#ifndef arrayoftriangles_h
#define arrayoftriangles_h

#define ArrayPointIndexError (-1)

#include <stdio.h>
#include <string.h>
#include "triangle.h"
#include "point.h"

typedef struct tag_arrayoftriangles{
    Triangle **storage;
    long count;
}ArrayOfTriangles;

ArrayOfTriangles *createArrayOfTriangles(long preservedCount);
void deleteArrayOfTriangles(ArrayOfTriangles *a);

int setTriangleAtIndex(ArrayOfTriangles *a, Triangle *value, int index);
Triangle *getPointAtIndex(ArrayOfTriangles *a, int index);

void printArrayOfTriangles(ArrayOfTriangles *a);
long countArrayOfTriangles(ArrayOfTriangles *a);

long reallocateInternalStorage(ArrayOfTriangles *a, int requestedCount);

#endif
