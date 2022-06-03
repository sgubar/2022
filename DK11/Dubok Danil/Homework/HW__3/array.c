#include "array.h"
#include <stdlib.h>
#include <string.h>

long reallocateStorage(Array *a, int requestedCount);

Array *createArrayTrap(int preservedCount)
{
      Array *array = (Array *)malloc(sizeof(Array));
      if (array != NULL)
            (
                array->count = (preservedCount > 0) ? preservedCount : 1);
      array->storage = (IT **)malloc(sizeof(IT *) * array->count);
      bzero(array->storage, sizeof(IT *) * array->count);
      return array;
}

void deleteArray(Array *a)
{
      if (a != NULL)
      {
            if (a->storage != NULL)
            {
                  free(a->storage);
            }

            free(a);
      }
}

int setTrapAtIndex(Array *a, IT *value, int index)
{
      if (a == NULL || index < 0)
      {
            return Error;
      }
      if (index >= a->count)
      {
            if (Error == reallocateStorage(a, index + 1))
            {
                  return Error;
            }
      }
      a->storage[index] = value;
      return index;
}

IT *getTrapAtIndex(Array *a, int index)
{
      if (NULL == a || index < 0 || index >= a->count)
      {
            return NULL;
      }

      return a->storage[index];
}

void printArray(Array *a)
{
      if (NULL == a)
      {
            return;
      }

      for (int i = 0; i < a->count; i++)
      {
            if (a->storage[i] != NULL)
            {
                  printTrap(a->storage[i]);
            }
            else
            {
                  printf("NULL");
            }

            if (i < (a->count - 1))
            {
                  printf(",");
            }
      }
      printf("\n");
}

long countArray(Array *a)
{
      if (NULL == a)
      {
            return Error;
      }

      return a->count;
}

long reallocateStorage(Array *a, int requestedCount)
{
      int count = requestedCount ++;

      IT **storage = (IT **)calloc(requestedCount, sizeof(IT *) * count);
      if (NULL == storage)
      {
            return Error;
      }
      memcpy(storage, a->storage, sizeof(IT *) * a->count);
      free(a->storage);

      a->storage = storage;
      a->count = count;

      return count;
}