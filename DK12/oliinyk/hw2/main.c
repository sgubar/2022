#include <stdlib.h>
#include <stdio.h>

#include "dk12_tool.c"

int main(void) {
	Point *center = createPoint(10, 0);
	Point *edge = createPoint(15, 12);
	Circle *circleOne = createCircle(center, edge);
	
	Circle *circleTwo = createCircleXY(12, 3, -12, 15);

	Point array[2];
	array[0].x = -5;
	array[0].y = -9;
	array[1].x = 12;
	array[1].y = 2;
	Circle *circleThree = createArrCircle(array);

    Circle *arrayCirles[3] = {circleOne, circleTwo, circleThree};
	printDetailCircle(3, arrayCirles);

	destroyCircle(circleOne);
	destroyCircle(circleTwo);
	free(circleThree);

	return 1;
}