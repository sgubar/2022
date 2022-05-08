#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool_array.h"
#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

// створення масиву
ellipseArray* createArray(int num) {
    ellipseArray* theResult = NULL;
    if (num > 0)

        theResult = (ellipseArray*)malloc(sizeof(ellipseArray));

        if (NULL != theResult) {

            theResult->ellipses = (Ellipse**)malloc(sizeof(Ellipse*) * num);
            
            if (NULL != theResult->ellipses) {
                
                theResult->number = num;
                theResult->count = 0;
            }
            else {   
                free(theResult);
                theResult = NULL;
            }
        }
    return theResult;
}

// функція додавання елементу до масиву
int addElement(ellipseArray* arr, Ellipse* el) {

    int theResult = -1;   
    
    if (NULL != arr && NULL != el && arr->count < arr->number) { // -1, якщо вставка невдала
        arr->ellipses[arr->count] = el;
        theResult = arr->count;
        arr->count++;
    }
    return theResult;
}

// функція вставки елементу за індексом

int insertElement(ellipseArray* arr, Ellipse* el, int index) {
    if (arr == NULL || index < 0) {
        return -1;
    }

    if (index >= arr->count) {
        if (-1 == reallocateInternalStorage(arr, index + 1)) {
            return -1;
        }
    }
    arr->ellipses[index] = el;
    return index;
};

//  функція друку масиву на екран
void printArray(ellipseArray* arr) {
    
    if (arr != NULL) {

        printf("Розмір масиву: %d \n", arr->number);
        printf("\nКількість еліпсів: %d \n\n", arr->count);

        for (int i = 0; i < arr->count; i++) {
            printEllipse(arr->ellipses[i]);
        }
    }
    else return;
}

// функція знищення масиву
void freeArray(ellipseArray* arr) {
    if (NULL != arr) {
        for (int i = 0; i < arr->count; i++) {
            destroyEllipse(arr->ellipses[i]);
        }
        free(arr->ellipses);
        free(arr);
    }
}

long reallocateInternalStorage(ellipseArray* arr, int requestedCount) {

    if (arr->count >= requestedCount) {
        return arr->count;
    }

    int count = requestedCount * 2;

    Ellipse** ellipses = (Ellipse**)malloc(sizeof(Ellipse*) * count);
    if (ellipses == NULL) {
        return -1;
    }

    ellipses, sizeof(Ellipse*)* count;
    ellipses, arr->ellipses, sizeof(Ellipse*)* arr->count;
    arr->ellipses; 

    arr->ellipses = ellipses;
    arr->count = count;
    free(arr->ellipses);

    return count;
}