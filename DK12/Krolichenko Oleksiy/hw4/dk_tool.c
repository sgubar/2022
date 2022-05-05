#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point* copyPointWithPoint(Point* aPoint);

Ellipse* createEllipse(Point* Centre, int* r, int* R) {
	
	Ellipse* result = NULL;

	if (NULL != Centre && NULL != r && NULL != R) {
		result = (Ellipse*)malloc(sizeof(Ellipse));
		if (NULL != result)
		{
			result->O = copyPointWithPoint(Centre);
			result->r = *r;
			result->R = *R;
		}
	}

	return result;
}

float SquareOfEllipse(Ellipse* aEllipse) {
	float Pi = 3.14159265;
	float result = 0.0;

	if (NULL != aEllipse) {
		result = Pi * aEllipse->r * aEllipse->R;
	}

	return result;
}

void printEllipse(Ellipse* aEllipse) 
{
	if (NULL != aEllipse) {
		printf("≈л≥пс: координати центру: (%d,%d), менша в≥сь: %d, б≥льша в≥сь: %d\n",
			aEllipse->O->x, aEllipse->O->y,
			aEllipse->r, aEllipse->R);
	}
}

Point* copyPointWithPoint(Point* aPoint) {
	Point* result = (Point*)malloc(sizeof(Point));
	if (NULL != result) {
	
		result->x = aPoint->x;
		result->y = aPoint->y;
	}
	return result;
}

void destroyEllipse(Ellipse* aEllipse) {
	if (NULL != aEllipse) {
		free(aEllipse->O);
		free(aEllipse);

	}
}