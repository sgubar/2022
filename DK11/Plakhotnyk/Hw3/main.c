#include "tool.h"
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    Point *center = createPoint(0, 0);
    Point *edge_1 = createPoint(3, 8);
    Point *edge_2 = createPoint(5, 4);
    Elips *elipsOne = createElips(center, edge_1, edge_2);

    Elips *elipsTwo = createElipsXY(-1, 5, 10, -3, 1, 9);

    Point *array[3];
    array[0] = createPoint(-8, -2);
    array[1] = createPoint(5, 3);
    array[2] = createPoint(12, 2);
    Elips *elipsThree = createArrElips(array);

    Elips *arrayElips[3] = {elipsOne, elipsTwo, elipsThree};

    ElipsArray *elipsArray = createElipsArray(3);

    int index0 = addElipsToArray(elipsArray, elipsOne);
    int index1 = addElipsToArray(elipsArray, elipsTwo);
    int index2 = addElipsToArray(elipsArray, elipsThree);
    int index3 = addElipsToArray(elipsArray, elipsThree);

    printf("\n1st index: %d\n", index0);
    printf("2nd index: %d\n", index1);
    printf("3rd index: %d\n", index2);
    printf("4th index: %d\n\n", index3);

    printDetailElips(getElipsByIndex(elipsArray, 0));

    index2 = setElipsAtIndex(elipsArray, elipsThree, 2);

    printDetailElips(getElipsByIndex(elipsArray, 2));

    printf("Arrays: %d\n\n", countElipsArray(elipsArray));

    printElipsArray(elipsArray);

    deleteElipsArray(elipsArray);

    printf("Three: %d\n", index2);
    printf("Four: %d\n", index3);

    printDetailElips(getElipsByIndex(elipsArray, 2));

    index2 = setElipsAtIndex(elipsArray, elipsThree, 2);

    printDetailElips(getElipsByIndex(elipsArray, 2));

    printf("Array count: %d\n\n", countElipsArray(elipsArray));

    printElipsArray(elipsArray);

    deleteElipsArray(elipsArray);

    return 1;
}
