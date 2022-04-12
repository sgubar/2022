#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"

int main()
{
	Point* O = createPoint(2, 3);
	Point* M = createPoint(4, 2);
	double radius = 5;

	Circle* circleA = createCircle(M, radius);
	Circle* circleB = createCirclePoints(O, M);
	Circle* circleC = createCircleCoord(-1, 4, 0, -3);

	infoCircle(circleA);
	infoCircle(circleB);
	infoCircle(circleC);

	destroyCircle(circleA);
	destroyCircle(circleB);
	destroyCircle(circleC);

	return 0;
}