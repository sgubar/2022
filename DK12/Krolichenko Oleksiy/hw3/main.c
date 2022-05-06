#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dk_tool_array.h"
#include "dk_tool.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    ellipseArray* theArray = createArray(3);

    Point Centre = { 50,50 };
    
    int r = 10;
    int R = 20;
    Ellipse* el1 = createEllipse(&Centre, &r, &R);
    addElement(theArray, el1);
    
    r = 30;
    R = 40;
    Ellipse* el2 = createEllipse(&Centre, &r, &R);
    addElement(theArray, el2);
    
    r = 50;
    R = 60;
    Ellipse* el3 = createEllipse(&Centre, &r, &R);
    addElement(theArray, el3);

    printArray(theArray);

    printf("\nПлоща 1 еліпсу = %f\n", SquareOfEllipse(el1));
    printf("Площа 2 еліпсу = %f\n", SquareOfEllipse(el2));
    printf("Площа 3 еліпсу = %f\n", SquareOfEllipse(el3));

    freeArray(theArray);
}