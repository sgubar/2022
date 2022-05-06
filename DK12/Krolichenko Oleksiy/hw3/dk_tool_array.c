#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool_array.h"
#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>

// створення масиву
ellipseArray* createArray(int aNumber) {
    ellipseArray* theResult = NULL;
    if (aNumber > 0)

        theResult = (ellipseArray*)malloc(sizeof(ellipseArray));

        if (NULL != theResult) {

            theResult->ellipses = (Ellipse**)malloc(sizeof(Ellipse*) * aNumber);
            
            if (NULL != theResult->ellipses) {
                
                theResult->number = aNumber;
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
int addElement(ellipseArray* anArray, Ellipse* aEllipse) {

    int theResult = -1;   
    
    if (NULL != anArray && NULL != aEllipse && anArray->count < anArray->number) { // -1, якщо вставка невдала
        anArray->ellipses[anArray->count] = aEllipse;
        theResult = anArray->count;
        anArray->count++;
    }
    return theResult;
}

//  функція друку масиву на екран
void printArray(ellipseArray* anArray) {
    
    if (anArray != NULL) {

        printf("Розмір масиву: %d \n", anArray->number);
        printf("\nКількість еліпсів: %d \n\n", anArray->count);

        for (int i = 0; i < anArray->count; i++) {
            printEllipse(anArray->ellipses[i]);
        }
    }
    else return;
}

// функція знищення масиву
void freeArray(ellipseArray* anArray) {
    if (NULL != anArray) {
        for (int i = 0; i < anArray->count; i++) {
            destroyEllipse(anArray->ellipses[i]);
        }
        free(anArray->ellipses);
        free(anArray);
    }
}