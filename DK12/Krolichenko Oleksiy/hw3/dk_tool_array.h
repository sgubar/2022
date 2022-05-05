#ifndef dk_tool_ellipse_h
#define dk_tool_ellipse_h

#include <stdio.h>
#include "dk_tool_array.h"
#include "dk_tool.h"


#define _CRT_SECURE_NO_WARNINGS

typedef struct tagEllipseArray {
	int number; 
	int count; 

	Ellipse** ellipses;
}ellipseArray;

ellipseArray* createArray(int aNumber);
void freeArray(ellipseArray* anArray);
int addElement(ellipseArray* anArray, Ellipse* aEllipse);
void printArray(ellipseArray* anArray);

#endif
