#include "tool.h"
#include <stdlib.h>
#include <math.h>


kvadrat* createSquare(Point* A, Point* B)
{
	kvadrat* theResult = NULL;

	if (NULL != A && NULL != B)
	{
		theResult = (kvadrat*)malloc(sizeof(kvadrat));
		if (NULL != theResult)
		{
			theResult->A = createPoint(A);
			theResult->B = createPoint(B);
		}
	}
	return theResult;
}

kvadrat* createSquareWithArrayOfPoint(Point* arrayOfPoint)
{
	kvadrat* theResult = (kvadrat*)malloc(sizeof(kvadrat));
	if (theResult != NULL)
	{
		theResult->A = createPoint(&arrayOfPoint[0]);
		theResult->B = createPoint(&arrayOfPoint[1]);
	}
	return theResult;
}

kvadrat* createSquareWithCoordinate(int xA, int yA, int xB, int yB)
{
	kvadrat* theResult = (kvadrat*)malloc(sizeof(kvadrat));

	if (theResult != NULL)
	{
		theResult->A = createPointWithCoordinate(xA, yA);
		theResult->B = createPointWithCoordinate(xB, yB);
	}

	return theResult;
}

Point* createPointWithCoordinate(int x, int y)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (theResult != NULL)
	{
		theResult->x = x;
		theResult->y = y;
	}
	return theResult;
}

Point* createPoint(Point* aPoint)
{
	Point* theResult = (Point*)malloc(sizeof(Point));
	if (NULL != theResult)
	{
		theResult->x = aPoint->x;
		theResult->y = aPoint->y;
	}
	return theResult;
}

void printSquare(kvadrat* aSquare)
{
	if (NULL != aSquare)
	{
		printf("[Square]. A(%d,%d) B(%d,%d)\n",
			aSquare->A->x, aSquare->A->y,
			aSquare->B->x, aSquare->B->y);
	}
}


float plOfsquare(kvadrat* aSquare)
{
	float result;
	if (aSquare != NULL)
	{
		float dx = (aSquare->B->x - aSquare->A->x);
		float dy = (aSquare->B->y - aSquare->A->y);
		result = sqrt(dx * dx + dy * dy) * 2;
		result *= result;
	}
	return result;
}

void destroySquare(kvadrat* aSquare)
{
	if (aSquare != NULL)
	{
		free(aSquare->A);
		free(aSquare->B);
		free(aSquare);
	}
}
