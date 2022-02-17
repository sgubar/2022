#include "dk12_tool.h"

int main(void) {
	Point *center = createPoint(10, 0);
	Point *edge = createPoint(15, 12);
	Circle *circleOne = createCircle(center, edge);
	
	Circle *circleTwo = createCircleXY(12, 3, -12, 15);

	Point *array[2];
    array[0] = createPoint(-5, 9);
    array[1] = createPoint(12, 2);
	Circle *circleThree = createArrCircle(array);

    Circle *arrayCirles[3] = {circleOne, circleTwo, circleThree};
    
	printDetailCircles((sizeof(arrayCirles) / sizeof(arrayCirles[0])), arrayCirles);

	destroyCircles((sizeof(arrayCirles) / sizeof(arrayCirles[0])), arrayCirles);

	return 1;
}