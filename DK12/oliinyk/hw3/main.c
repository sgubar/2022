#include "dk12_tool.h"
#include <stdio.h>

int main(void) {
    Point *center = createPoint(10, 0);
    Point *edge = createPoint(15, 12);
    Circle *circleOne = createCircle(center, edge);

    Circle *circleTwo = createCircleXY(12, 3, -12, 15);

    Point *pointsArray[2];
    pointsArray[0] = createPoint(-5, 9);
    pointsArray[1] = createPoint(12, 2);
    Circle *circleThree = createArrCircle(pointsArray);

    CircleArray *circleArray = createCircleArray(3);//* count

    int index0 = addCircleToArray(circleArray, circleOne);
    int index1 = addCircleToArray(circleArray, circleTwo);
    int index2 = addCircleToArray(circleArray, circleOne);
    int index3 = addCircleToArray(circleArray, circleThree);//? if more than tha maximum count

    printf("One: %d\n", index0);
    printf("Two: %d\n", index1);
    printf("Three: %d\n", index2);
    printf("Four: %d\n", index3);//! error CircleArrayIndexError (-1)

    printDetailCircle(getCircleAtIndex(circleArray, 2));//? circleOne in array index 2

    index2 = setCircleAtIndex(circleArray, circleThree, 2);

    printDetailCircle(getCircleAtIndex(circleArray, 2));//? circleThree in array index 2

    printf("Array count: %d\n\n", countCircleArray(circleArray));
    
    printCircleArray(circleArray);

    deleteCircleArray(circleArray);//? free array
    printf("Free array!\n");

    return 1;
}