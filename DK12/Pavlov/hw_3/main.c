#include "dk12_tool.h"
#include <stdio.h>

// Даны координаты вершин трапеции ABCD: А (-2; -2), В (-3; 1), С (7; 7) и D (3; 1)

int main(void) {
	Point *point1 = createPoint(6, 6);
	Point *point2 = createPoint(3, 2);
    Point *point3 = createPoint(5, 2);
    Point *point4 = createPoint(9, 6);

	Trapezoid *trapezoidOne = createTrapezoid(point1, point2, point3, point4);
	
	Trapezoid *trapezoidTwo = createTrapezoidXY(6, 6, 3, 2, 5, 2, 9, 6);

	Point *array[4];
    array[0] = createPoint(6, 6);
    array[1] = createPoint(3, 2);
    array[2] = createPoint(5, 2);
    array[3] = createPoint(9, 6);
	Trapezoid *trapezoidThree = createArrayTrapezoid(array);

     TrapezoidArray *trapezoidArray = createTrapezoidArray(3);

    int index0 = addTrapezoidToArray(trapezoidArray, trapezoidOne);
    int index1 = addTrapezoidToArray(trapezoidArray, trapezoidTwo);
    int index2 = addTrapezoidToArray(trapezoidArray, trapezoidOne);
    int index3 = addTrapezoidToArray(trapezoidArray, trapezoidThree);

    printf("One: %d\n", index0);
    printf("Two: %d\n", index1);
    printf("Three: %d\n", index2);
    printf("Four: %d\n", index3);

    printDetailTrapezoid(getTrapezoidAtIndex(trapezoidArray, 2));

    index2 = setTrapezoidAtIndex(trapezoidArray, trapezoidThree, 2);

    printDetailTrapezoid(getTrapezoidAtIndex(trapezoidArray, 2));

    printf("Array count: %d\n\n", countTrapezoidArray(trapezoidArray));
    
    printTrapezoidArray(trapezoidArray);

    deleteTrapezoidArray(trapezoidArray);
    printf("Free array!\n");

	return 1;
} 