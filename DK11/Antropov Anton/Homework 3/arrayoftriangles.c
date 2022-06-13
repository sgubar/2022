#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "arrayoftriangles.h"

ArrayOfTriangles *createArrayOfTriangles(long preservedCount) {
    ArrayOfTriangles *array = (ArrayOfTriangles *)malloc(sizeof(ArrayOfTriangles));

    if(array != NULL )(array->count = (preservedCount > 0) ? preservedCount : 1);

        array->storage = (Triangle **)malloc(sizeof(Triangle *) * array->count);

        bzero(array->storage, sizeof(Triangle *) * array->count);

    return array;
}

void deleteArrayOfTriangles(ArrayOfTriangles *array) {
    if(array != NULL) {

        if (array->storage != NULL) {
            free(array->storage);
        }

        free(array);
    }
}

int setTriangleAtIndex(ArrayOfTriangles *array, Triangle *value, int index) {
    if (array == NULL || index < 0 ) {
            return ArrayPointIndexError;
    }
    if (index >= array->count) {

        if (ArrayPointIndexError == reallocateInternalStorage(array, index + 1)){
            return ArrayPointIndexError;
        }
    }
    array->storage[index] = value;
    return index;
}

Triangle *getPointAtIndex(ArrayOfTriangles *array, int index) {
    if (array == NULL || index < 0 || index >=array->count ) {
            return NULL;
    }
    return array->storage[index];
}

void printArrayOfTriangles(ArrayOfTriangles *array) {
    for (int i = 0; i < array->count; i++) {

        if(array->storage [i] != NULL){
            printTriangle(array->storage[i]);
        } else {
            
        printf ("NULL");
        }
        if (i < (array->count -1)){
            printf(",");
        }
    }
    printf("\n");
}
long countArrayOfTriangles(ArrayOfTriangles *array)
{
    if (array == NULL){
            return ArrayPointIndexError;
    }
    return array->count;
}

long reallocateInternalStorage(ArrayOfTriangles *array, int requestedCount)
{
    if (array->count >= requestedCount ){
        return array->count;
    }
    int count = requestedCount * 2;
    Triangle **storage = (Triangle **)malloc(sizeof(Triangle *) * count);
    if (storage == NULL){
        return ArrayPointIndexError;
    }
    bzero(storage, sizeof(Triangle *) * count);
    memcpy(storage, array->storage, sizeof(Triangle *) * array->count);
    free(array->storage);

    array->storage = storage;
    array->count = count;

    return count;
}
