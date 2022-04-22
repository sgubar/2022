#include "arraysquare.h"
#include <stdlib.h>
#include <string.h>

long reallocateInternalStorage(ArraySquare *a, int requestedCount);

ArraySquare *createArraySquare(long preservedCount)
{
    ArraySquare *array = (ArraySquare *)malloc(sizeof(ArraySquare));
    if (NULL != array )
    (array->count = (preservedCount > 0) ? preservedCount : 1);
    array->storage = (Square **)malloc(sizeof(Square *) * array->count);
    bzero(array->storage, sizeof(Square *) * array->count);

        return array;
}
void deleteArraySquare(ArraySquare *a)
{
    if (NULL != a){
        if (NULL != a->storage){
            free(a->storage);
        }
        free(a);
    }
}

int setSquareAtIndex(ArraySquare *a, Square *value, int index)
{
    if (NULL == a || index < 0 ){
            return ArraySquareIndexError;
    }
    if (index >= a->count){
        if (ArraySquareIndexError == reallocateInternalStorage(a, index + 1)){
            return ArraySquareIndexError;
        }
    }
    a->storage[index] = value;
    return index;
}
Square *getSquareAtIndex (ArraySquare *a, int index)
{
    if (NULL == a || index < 0 || index >=a->count ){
            return NULL;
    }
    return a -> storage[index];
}

void printArraySquare (ArraySquare *a){
    if (NULL == a  ){
            return NULL;
    }
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
long countArraySquare(ArraySquare *a)
{
    if (NULL == a  ){
            return ArraySquareIndexError;
    }
    return a->count;
}

long reallocateInternalStorage(ArraySquare *a, int requestedCount)
{
    if (a->count >= requestedCount ){
        return a->count;
    }
    int count = requestedCount * 2;
    Square **storage = (Square **)malloc(sizeof(Square *) * count);
    if (NULL == storage){
        return ArraySquareIndexError;
    }
    bzero(storage, sizeof(Square *) * count);
    memcpy(storage, a->storage, sizeof(Square *) * a->count);
    free(a->storage);

    a->storage = storage;
    a->count = count;

    return count;
}
