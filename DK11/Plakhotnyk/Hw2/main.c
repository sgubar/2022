#include "tool.h"
#include <stdlib.h>
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

    printDetailElips((sizeof(arrayElips) / sizeof(arrayElips[0])), arrayElips);

    destroyElips((sizeof(arrayElips) / sizeof(arrayElips[0])), arrayElips);

    return 1;
}
