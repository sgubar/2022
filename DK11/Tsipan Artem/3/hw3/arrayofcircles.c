#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "arrayofcircles.h"

ArrayOfCircles *createArrayOfCircles(long preservedCount)
{
    ArrayOfCircles *array = (ArrayOfCircles *)malloc(sizeof(ArrayOfCircles));
    if(array != NULL )(
        array->count = (preservedCount > 0) ? preservedCount : 1);
        array->storage = (Circle **)malloc(sizeof(Circle *) * array->count);
        bzero(array->storage, sizeof(Circle *) * array->count);
    return array;
}

void deleteArrayOfCircles(ArrayOfCircles *a)
{
    if(a != NULL){
        if(a->storage != NULL){
            free(a->storage);
        }
        free(a);
    }
}

int setCircleAtIndex(ArrayOfCircles *a, Circle *value, int index)
{
    if(a == NULL || index < 0 ){
            return ArrayPointIndexError;
    }
    if(index >= a->count){
        if(ArrayPointIndexError == reallocateInternalStorage(a, index + 1)){
            return ArrayPointIndexError;
        }
    }
    a->storage[index] = value;
    return index;
}
Circle *getPointAtIndex (ArrayOfCircles *a, int index)
{
    if(a == NULL || index < 0 || index >=a->count ){
            return NULL;
    }
    return a -> storage[index];
}

void printArrayOfCircles(ArrayOfCircles *a){
    for(int i = 0; i < a->count; i++){
        if(a->storage [i] != NULL){
            printCircle(a->storage[i]);
        }else{
        printf ("NULL");
        }
        if(i < (a->count -1)){
            printf(",");
        }
    }
    printf("\n");
}
long countArrayOfCircles(ArrayOfCircles *a)
{
    if(a == NULL){
            return ArrayPointIndexError;
    }
    return a->count;
}

long reallocateInternalStorage(ArrayOfCircles *a, int requestedCount)
{
    if(a->count >= requestedCount ){
        return a->count;
    }
    int count = requestedCount * 2;
    Circle **storage = (Circle **)malloc(sizeof(Circle *) * count);
    if(storage == NULL){
        return ArrayPointIndexError;
    }
    bzero(storage, sizeof(Circle *) * count);
    memcpy(storage, a->storage, sizeof(Circle *) * a->count);
    free(a->storage);

    a->storage = storage;
    a->count = count;

    return count;
}
