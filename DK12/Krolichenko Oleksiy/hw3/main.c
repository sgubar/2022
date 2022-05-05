#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool_array.h"
#include "dk_tool.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ellipseArray* theArray = createArray(5);
    Point Centre = { 50,50 };
    int R = 10;
    int r = 20;

    Ellipse* El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("Площа 1 еліпсу = %f\n", SquareOfEllipse(El1));


    R = 30;
    r = 40;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("Площа 2 еліпсу = %f\n", SquareOfEllipse(El1));


    R = 50;
    r = 60;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("Площа 3 еліпсу = %f\n", SquareOfEllipse(El1));


    R = 70;
    r = 80;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("Площа 4 еліпсу = %f\n", SquareOfEllipse(El1));


    R = 90;
    r = 100;

    El1 = createEllipse(&Centre, &R, &r);
    addElement(theArray, El1);
    printf("Площа 5 еліпсу = %f\n", SquareOfEllipse(El1));
    printArray(theArray);

    FILE* theFile = fopen("array.json", "a+");
    
    if (theFile != NULL) {
        printf("");
    }
    else
        return 0;

    json(theFile, theArray);
    freeArray(theArray);
    fflush(theFile);
    fclose(theFile);

    return 0;
}