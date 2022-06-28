#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "array_rectangle.h"

ArrayRectangle *createArrayRectangle(long preservedCount)
{
    ArrayRectangle *array = (ArrayRectangle *)malloc(sizeof(ArrayRectangle));
    if(array != NULL )(
        array->count = (preservedCount > 0) ? preservedCount : 1);
        array->storage = (Rectangle **)malloc(sizeof(Rectangle *) * array->count);
        bzero(array->storage, sizeof(Rectangle *) * array->count);
    return array;
}
void deleteArrayRectangle(ArrayRectangle *a)
{
    if (a != NULL){
        if (a->storage != NULL){
            free(a->storage);
        }
        free(a);
    }
}
int setRectangleAtIndex(ArrayRectangle *a, Rectangle *value, int index)
{
    if (a == NULL || index < 0 ){
            return ArrayPointIndexError;
    }
    if (index >= a->count){
        if (ArrayPointIndexError == reallocateInternalStorage(a, index + 1)){
            return ArrayPointIndexError;
        }
    }
    a->storage[index] = value;
    return index;
}
Rectangle *getPointAtIndex (ArrayRectangle *a, int index)
{
    if (a == NULL || index < 0 || index >=a->count ){
            return NULL;
    }
    return a -> storage[index];
}
void printArrayRectangle(ArrayRectangle *a){
    for (int i = 0; i < a->count; i++){
        if(a->storage [i] != NULL){
            printRectangle(a->storage[i]);
        }else{
        printf ("NULL");
        }
        if (i < (a->count -1)){
            printf(",");
        }
    }
    printf("\n");
}
long countArrayRectangle(ArrayRectangle *a)
{
    if (a == NULL){
            return ArrayPointIndexError;
    }
    return a->count;
}
long reallocateInternalStorage(ArrayRectangle *a, int requestedCount)
{
    if (a->count >= requestedCount ){
        return a->count;
    }
    int count = requestedCount * 2;
    Rectangle **storage = (Rectangle **)malloc(sizeof(Rectangle *) * count);
    if (storage == NULL){
        return ArrayPointIndexError;
    }
    bzero(storage, sizeof(Rectangle *) * count);
    memcpy(storage, a->storage, sizeof(Rectangle *) * a->count);
    free(a->storage);

    a->storage = storage;
    a->count = count;

    return count;
}
