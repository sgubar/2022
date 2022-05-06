#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "arrayfigures.h"

ArrayFigures *createArrayFigures(long preservedCount)
{
    ArrayFigures *array = (ArrayFigures *)malloc(sizeof(ArrayFigures));
    if(array != NULL )(
        array->count = (preservedCount > 0) ? preservedCount : 1);
        array->storage = (Square **)malloc(sizeof(Square *) * array->count);
        bzero(array->storage, sizeof(Square *) * array->count);
    return array;
}

void deleteArrayFigures(ArrayFigures *a)
{
    if (a != NULL){
        if (a->storage != NULL){
            free(a->storage);
        }
        free(a);
    }
}

int setSquareAtIndex(ArrayFigures *a, Square *value, int index)
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
Square *getPointAtIndex (ArrayFigures *a, int index)
{
    if (a == NULL || index < 0 || index >=a->count ){
            return NULL;
    }
    return a -> storage[index];
}

void printArrayFigures(ArrayFigures *a){
    for (int i = 0; i < a->count; i++){
        if(a->storage [i] != NULL){
            printSquare(a->storage[i]);
        }else{
        printf ("NULL");
        }
        if (i < (a->count -1)){
            printf(",");
        }
    }
    printf("\n");
}
long countArrayFigures(ArrayFigures *a)
{
    if (a == NULL){
            return ArrayPointIndexError;
    }
    return a->count;
}

long reallocateInternalStorage(ArrayFigures *a, int requestedCount)
{
    if (a->count >= requestedCount ){
        return a->count;
    }
    int count = requestedCount * 2;
    Square **storage = (Square **)malloc(sizeof(Square *) * count);
    if (storage == NULL){
        return ArrayPointIndexError;
    }
    bzero(storage, sizeof(Square *) * count);
    memcpy(storage, a->storage, sizeof(Square *) * a->count);
    free(a->storage);

    a->storage = storage;
    a->count = count;

    return count;
}
