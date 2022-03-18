#include <stdio.h>
#include <stdlib.h>
#include "arraypoints.h"
#include "line.h"
#include "dpline.h"
int main()
{
    Point *p = createPoint(5, 6);

    ArrayPoints *a=createArrayPoints(2);
    printArrayPoints(a);

    setPointAtIndex(a, p, 0);
    printArrayPoints(a);

    setPointAtIndex(a, p, 4);
    printArrayPoints(a);

    printf("Polyline test...\n");
    DPLine *dp = createDPLine();

    addPointToDPLine(dp, p);
    printDPLine(dp);
    printf("len: %f\n", lenghtDPLine(dp));

    addPointByXYToDPLine(dp, 7, 8);
    printDPLine(dp);
    printf("len: %f\n", lenghtDPLine(dp));

    addPointByXYToDPLine(dp, 97, 78);
    printDPLine(dp);
    printf("len: %f\n", lenghtDPLine(dp));

    addPointByXYToDPLine(dp, 87, 58);
    printDPLine(dp);
    printf("len: %f\n", lenghtDPLine(dp));

    addPointByXYToDPLine(dp, 77, 88);
    printDPLine(dp);
    printf("len: %f\n", lenghtDPLine(dp));

    addPointByXYToDPLine(dp, 37, 48);
    printDPLine(dp);
    printf("len: %f\n", lenghtDPLine(dp));

    printf("Hello world!\n");
    deleteArrayPoints(a);

    deletePoint(p);
    deleteDPLine(dp);
    deleteArrayPoints(a);

    return 0;
}
