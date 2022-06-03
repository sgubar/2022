#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include "point.h"
#include "circle.h"

#define StorageIndexError (-1)

typedef struct Array
{
    Circle **storage;
    long count;
}Storage;

Storage *createStorage(long preservedCount);
void deleteStorage(Storage *s);

int setCircleByIndex(Storage *s, Circle *value, int index);
Circle *getCircleByIndex(Storage *s, int index);

void printStorage(Storage *s);
long countStorage(Storage *s);

#endif // ARRAY_H_INCLUDED
