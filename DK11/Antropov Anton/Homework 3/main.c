#include "point.h"
#include "triangle.h"
#include "arrayoftriangles.h"

int main()
{
    int x1 = inputCoords(1);
    int y1 = inputCoords(2);
    int x2 = inputCoords(3);
    int y2 = inputCoords(4);
    int x3 = inputCoords(5);
    int y3 = inputCoords(6);

    Point *p1 = createPoint(x1,y1);
    Point *p2 = createPoint(x2,y2);
    Point *p3 = createPoint(x3,y3);

    Triangle *triangle = createTriangleByPoints(p1,p2,p3);
    printf("\nТрикутник:\n");
    printTriangle(triangle);

    Point *center = centerTriangle(triangle);
    printf("Центр трикутника: ");
    printPoint(center);
    printf("\n");

    printf("\nМасив трикутників: \n");
    ArrayOfTriangles *array = createArrayOfTriangles(5);
    printArrayOfTriangles(array);

    setTriangleAtIndex(array,triangle,0);
    printArrayOfTriangles(array);
    setTriangleAtIndex(array,triangle,4);
    printArrayOfTriangles(array);

    deleteArrayOfTriangles(array);
    deleteTriangle(triangle);
    
    deletePoint(p1);
    deletePoint(p2);
    deletePoint(p3);
}

