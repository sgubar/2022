#ifndef arrayTrap_h
#define arrayTrap_h

#include <stdio.h>
#include "point.h"
#include "trap.h"

#define Error (-1)

typedef struct arrayf
{
      IT **storage;
      long count;
} Array;

Array *createArrayTrap(int preservedCount);
void deleteArray(Array *a);

int setTrapAtIndex(Array *a, IT *value, int index);
IT *getTrapAtIndex(Array *a, int index);

void printArray(Array *a);
long countArray(Array *a);

#endif 