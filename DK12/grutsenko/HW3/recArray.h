#ifndef RECARRAY_H
#define RECARRAY_H
#include "rec.h"

typedef struct tag_arrayRectangle {
    Rectangle **array_ptr;
    int size;
    int count;
} ArrayRectangle;
    
ArrayRectangle *createArrayRectangle(int size);

int addRectangleToArray(ArrayRectangle *array, Rectangle *rec);

Rectangle *getRectangleFromArrayByIndex(ArrayRectangle *array, int index);

int setRectangleAtIndex(ArrayRectangle *array, Rectangle *rec, int index);

void printArrayRectangle(ArrayRectangle *array);

void deleteArrayRectangle(ArrayRectangle *array);





#endif