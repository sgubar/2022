#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

Point* copyPointWithPoint(Point* aPoint);

Ellipse* createEllipse(Point* Centre, int* R, int* r) {

	Ellipse* result = NULL;

	if (NULL != Centre && NULL != R && NULL != r) {
		
		result = (Ellipse*)malloc(sizeof(Ellipse));
		if (NULL != result) {
			
			result->O = copyPointWithPoint(Centre);
			result->R = *R;
			result->r = *r;
		}
	}

	return result;
}

float SquareOfEllipse(Ellipse* aEllipse) {
	float Pi = 3.14159265;
	float theResult = 0.0;

	if (NULL != aEllipse) {
		theResult = Pi * aEllipse->R * aEllipse->r;
	}

	return theResult;
}

void destroyEllipse(Ellipse* aEllipse) {

	if (NULL != aEllipse) {
		free(aEllipse->O);
		free(aEllipse); 

	}
}


void printEllipse(Ellipse* aEllipse) {

	if (NULL != aEllipse) {
		printf("≈л≥пс: координати центру: (%d,%d), б≥льша в≥сь: %d, менша в≥сь: %d\n",
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

void pointsJson(FILE* aFile, Point* aPoint) {

	if (NULL == aPoint || NULL == aFile) {
		return;
	}

	fprintf(aFile, "{\"x\" : %d, \"y\" : %d}", aPoint->x, aPoint->y);
}

void ellipsesJson(FILE* aFile, Ellipse* aEllipse) {

	if (NULL == aEllipse || NULL == aFile) {
		return;
	}

	fprintf(aFile, "{\n\"O\" : ");
	pointsJson(aFile, aEllipse->O);
	fprintf(aFile, ", \n\"R\" : %d", aEllipse->R);
	fprintf(aFile, ", \n\"r\" : %d", aEllipse->r);
	fprintf(aFile, "\n}");
}