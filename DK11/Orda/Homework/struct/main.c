#include <stdio.h>
#include <math.h>

#include "point.h"
#include "line.h"

int main(){
    int x1, y1, x2, y2;

    printf("Введіть координати центра кола, спочатку х, потім у:\n");
    scanf("%d %d", &x1, &y1);
    printf("Введіть координати точки яка належить колу, спочатку х, потім у:\n");
    scanf("%d %d", &x2, &y2);

    Point *A = createPoint(x1, y1);
    Point *B = createPoint(x2, y2);

    Line *R = createLine(A, B);

    double r = lenghtLine(R);

    double s = circleArea(R);

    printf("Центр кола в точці:");
    printPoint(A);
    printf("\n");
    printf("З радіусом кола:");
    printLine(R);
    printf("Площею: %0.2f\n", s);
    
    deletPoint(A);
    deletPoint(B);
    deletLine(R);
}