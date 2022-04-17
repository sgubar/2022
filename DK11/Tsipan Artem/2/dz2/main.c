#define _CRT_SECURE_NO_WARNINGS
#include "dk_tools.h"

int main()
{
	Point* O = createPoint(2, 3);
	Point* N = createPoint(4, 2);
	double radius = 5;

	Circle* circleA = createCircle(N, radius);
	Circle* circleB = createCirclePoints(O, N);
	Circle* circleC = createCircleCoord(-1, 4, 0, -3);

	circleInfo(circleA);
	circleInfo(circleB);
	circleInfo(circleC);

	destroy(circleA);
	destroy(circleB);
	destroy(circleC);

	return 0;
}
