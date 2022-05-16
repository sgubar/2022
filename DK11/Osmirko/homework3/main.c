#include "circle.h"
#include <stdio.h>

int main(void) {
    Point *center = createPoint(5, 0);
    Point *edge = createPoint(8, 6);
    Circle *circleOne = createCircle(center, edge);

    Circle *circleTwo = createCircleXY(6, 1, -6, 7);

    Point *pointsArray[2];
    pointsArray[0] = createPoint(-3, 5);
    pointsArray[1] = createPoint(6, 1);
    Circle *circleThree = createArrCircle(pointsArray);

    CircleArray *circleArray = createCircleArray(3);

    int index0 = addCircleToArray(circleArray, circleOne);
    int index1 = addCircleToArray(circleArray, circleTwo);
    int index2 = addCircleToArray(circleArray, circleOne);
    int index3 = addCircleToArray(circleArray, circleThree);
    printf("1: %d\n", index0);
    printf("2: %d\n", index1);
    printf("3: %d\n", index2);
    printf("4: %d\n", index3);

    printDetailCircle(getCircleAtIndex(circleArray, 2));

    index2 = setCircleAtIndex(circleArray, circleThree, 2);

    printDetailCircle(getCircleAtIndex(circleArray, 2));
    printf("Array count: %d\n\n", countCircleArray(circleArray));
    printCircleArray(circleArray);

    deleteCircleArray(circleArray);
    printf("Free array!\n");

    return 1;
}
