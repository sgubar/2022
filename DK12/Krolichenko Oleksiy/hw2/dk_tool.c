#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Point* copyPointWithPoint(Point* aPoint);

Ellipse* createEllipse(Point* Centre, int* R, int* r) {
	
	Ellipse* result = NULL;

	if (NULL != Centre && NULL != R && NULL != r) {
		result = (Ellipse*)malloc(sizeof(Ellipse));
		if (NULL != result)
		{
			result->O = copyPointWithPoint(Centre);
			result->R = *R;
			result->r = *r;
		}
	}

	return result;
}

float SquareOfEllipse(Ellipse* aEllipse) {
	float Pi = 3.14159265;
	float result = 0.0;

	if (NULL != aEllipse) {
		result = Pi * aEllipse->R * aEllipse->r;
	}

	return result;
}

void printEllipse(Ellipse* aEllipse) 
{
	if (NULL != aEllipse) {
		printf("Еліпс: координати центру: (%d,%d), більшої вісі: %d, меншої вісі: %d\n",
			aEllipse->O->x, aEllipse->O->y,
			aEllipse->R, aEllipse->r);
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