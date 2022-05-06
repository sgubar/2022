#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

Point* copyPointWithPoint(Point* point);

Ellipse* createEllipse(Point* Centre, int* r, int* R) {

	Ellipse* result = NULL;

	if (NULL != Centre && NULL != r && NULL != R) {
		
		result = (Ellipse*)malloc(sizeof(Ellipse));
		if (NULL != result) {
			
			result->O = copyPointWithPoint(Centre);
			result->r = *r;
			result->R = *R;
		}
	}

	return result;
}

float SquareOfEllipse(Ellipse* el) {
	float Pi = 3.14159265;
	float theResult = 0.0;

	if (NULL != el) {
		theResult = Pi * el->r * el->R;
	}

	return theResult;
}

void destroyEllipse(Ellipse* el) {

	if (NULL != el) {
		free(el->O);
		free(el); 

	}
}

void printEllipse(Ellipse* el) {

	if (NULL != el) {
		printf("≈л≥пс: координати центру: (%d,%d), менша в≥сь: %d, б≥льша в≥сь: %d\n",
			el->O->x, el->O->y,
			el->r, el->R);
	}
}

Point* copyPointWithPoint(Point* point) {
	
	Point* result = (Point*)malloc(sizeof(Point));
	
	if (NULL != result) {

		result->x = point->x;
		result->y = point->y;
	}

	return result;
}
