#include <stdio.h>
#include "tool.h"

int main(int argc, const char *argv[])
{
    float pl = 0;
    Point A = {0, 0};
    Point B = {4, 0};
    Point C = {0, 0};
    Point D = {6, 16};
    Point arrayOfPoint[2] = {C, D};

    Kvadrat *a = createSquare(&A, &B);
    Kvadrat *b = createSquareWithCoordinate(3, 7, 0, 5);
    Kvadrat *c = createSquareWithArrayOfPoint(arrayOfPoint);

    KvadratArray *KvadratArray = createKvadratArray(3);

    int kvadrat1 = addKvadratToArray(KvadratArray, a);
    int kvadrat2 = addKvadratToArray(KvadratArray, b);
    int kvadrat3 = addKvadratToArray(KvadratArray, c);

    printf("One: %d\n", kvadrat1);
    printf("Two: %d\n", kvadrat2);
    printf("Three: %d\n", kvadrat3);

    printDetailKvadrat(getKvadratAtIndex(KvadratArray, 2));

    kvadrat3 = setKvadratAtIndex(KvadratArray, b, 2);

    printDetailKvadrat(getKvadratAtIndex(KvadratArray, 2));

    printf("Count: %d\n\n", countKvadratArray(KvadratArray));
    
    printKvadratArray(KvadratArray);

    deleteKvadratArray(KvadratArray);
    printf("Free!\n");
    return 0;
}
