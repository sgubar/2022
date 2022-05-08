#define _CRT_SECURE_NO_WARNINGS

#ifndef dk_tool_ellipse_h
#define dk_tool_ellipse_h

#include <stdio.h>
#include "dk_tool_array.h"
#include "dk_tool.h"

typedef struct tagEllipseArray {
	int number; 
	int count; 
	Ellipse** ellipses;
}ellipseArray;

ellipseArray* createArray(int num);
void freeArray(ellipseArray* arr);
int addElement(ellipseArray* arr, Ellipse* el);
int insertElement(ellipseArray* arr, Ellipse* el, int index);
void printArray(ellipseArray* arr);

#endif
