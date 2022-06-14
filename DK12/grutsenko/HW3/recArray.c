#include <stdlib.h>
#include <stdio.h>
#include "rec.h"
#include "recArray.h"

ArrayRectangle *createArrayRectangle(int size) {
    if (size == 0) {
        return NULL;
    }
    ArrayRectangle *array = (ArrayRectangle*)malloc(sizeof(ArrayRectangle));
    if (NULL != array) {
        array->array_ptr = (Rectangle**)malloc(sizeof(Rectangle*) * size);
        array->size = size;
        array->count = 0;
    }
    return array;
}//

int addRectangleToArray(ArrayRectangle *array, Rectangle *rec) {
    if (NULL == array || NULL == rec) {
        return -1;
	}
    if (array->count == array->size) {
        printf("array is full\n");
        return -1;
    }
    array->array_ptr[array->count] = rec;
    array->count ++;

    return array->count-1;
}//


Rectangle *getRectangleFromArrayByIndex(ArrayRectangle *array, int index) {
    if (NULL == array ||  index < 0 ||  index >= array->size) {
        return NULL;
    }
    return array->array_ptr[index];
}//


int setRectangleAtIndex(ArrayRectangle *array, Rectangle *rec, int index) {
    if (NULL == array ||  NULL == rec ||  index < 0 || index >= array->size) {
        return -1;
    }
    array->array_ptr[index] = rec;
    
    return index;
}//

void printArrayRectangle(ArrayRectangle *array) {
    if (NULL == array) {
        return;
    }
    for (int i=0; i < array->size; i++) {
        if (array->array_ptr[i] != NULL) {
            printf("Rectangle [%d]:\n", i);
            printRectangle(array->array_ptr[i]);
        } else {
            printf("none\n");
        }
    }
}//

void deleteArrayRectangle(ArrayRectangle *array) {
    if (NULL != array) {
        if (NULL != array->array_ptr) {
            free(array->array_ptr);
        }
        free(array);
    }
}//
