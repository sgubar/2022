#include <stdio.h>
#include <stdlib.h>
#include "arraysquare.h"


int main()
int main(void) {
	Point *point1 = createPoint(1, 1);
	Point *point2 = createPoint(1, 4);
    Point *point3 = createPoint(4, 4);
    Point *point4 = createPoint(4, 1);

	Square *squareOne = createSquare(point1, point2, point3, point4);
	
	Square*squareTwo = createSquareXY(1, 1, 1, 4, 4, 4, 4, 1);

	Point *array[4];
    array[0] = createPoint(1, 1);
    array[1] = createPoint(1, 4);
    array[2] = createPoint(4, 4);
    array[3] = createPoint(4, 1);
	Square *squareThree = createArraySquare(array);

     SquareArray *squareArray = createSquareArray(3);

    int index0 = addSquareToArray(squareArray, squareOne);
    int index1 = addSquareToArray(squareArray, squareTwo);
    int index2 = addSquareToArray(squareArray, squareOne);
    int index3 = addSquareToArray(squareArray, squareThree);

    printf("One: %d\n", index0);
    printf("Two: %d\n", index1);
    printf("Three: %d\n", index2);
    printf("Four: %d\n", index3);

    printDetailSquare(getSquareAtIndex(squareArray, 2));

    index2 = setSquareAtIndex(squareArray, squareFour, 2);

    printDetailSquare(getSquareAtIndex(squareArray, 2));

    printf("Array count: %d\n\n", countSquareArray(squareArray));
    
    printSquareArray(squareArray);

    deleteSquareArray(squareArray);
    printf("Four array!\n");

	return 1;
