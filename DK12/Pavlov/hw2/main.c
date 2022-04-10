#include "dk12_tool.h"

// Даны координаты вершин трапеции ABCD: А (-2; -2), В (-3; 1), С (7; 7) и D (3; 1)

int main(void) {
	Point *point1 = createPoint(1, 2);
	Point *point2 = createPoint(3, 3);
    Point *point3 = createPoint(5, 2544);
    Point *point4 = createPoint(9, 6);

	Trapezoid *TrapezoidOne = createTrapezoid(point1, point2, point3, point4);
	
	Trapezoid *TrapezoidTwo = createTrapezoidXY(6, 6, 3, 2, 5, 2, 9, 6);

	Point *array[4];
    array[0] = createPoint(6, 6);
    array[1] = createPoint(3, 2);
    array[2] = createPoint(5, 2);
    array[3] = createPoint(9, 6);
	Trapezoid *TrapezoidThree = createArrayTrapezoid(array);

    double s1 = areaTrapezoid(TrapezoidOne);
    double s2 = areaTrapezoid(TrapezoidTwo);
    double s3 = areaTrapezoid(TrapezoidThree);

	infoTrapezoid(TrapezoidOne, s1);
    infoTrapezoid(TrapezoidTwo, s2);
    infoTrapezoid(TrapezoidThree, s3);

    destroyTrapezoid(TrapezoidOne);
    destroyTrapezoid(TrapezoidThree);
    destroyTrapezoid(TrapezoidTwo);

	return 1;
} 