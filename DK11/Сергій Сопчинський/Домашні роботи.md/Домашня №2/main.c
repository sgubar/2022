#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"

int main()
{
	Point* O = createPoint(40, 40);
	Point* M = createPoint(33, 12);
	double radius = 13;
	Circle* circleA = createCircle(M, radius);
	Circle* circleB = createCirclePoints(O, M);
	Circle* circleC = createCircleCoord(23, -4, -11, 1);
	infoCircle(circleA);
	infoCircle(circleB);
	infoCircle(circleC);
	destroyCircle(circleA);
	destroyCircle(circleB);
	destroyCircle(circleC);
	return 0;
}
