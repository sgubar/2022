#include <stdio.h>
#include <string.h>
#include "point.h"
#include "circle.h"
#include "arrayofcircles.h"

int main()
{
    Point *point1 = createPoint(6, 5);
    Point *point2 = createPoint(3, 9);
    Circle *circle = createCircleByPoints(point1,point2);
    printf("Друкування Кола:\n\n");
    printCircle(circle);
    printf("Радіус кола: %f\n",radiusCircle(circle));
    
    ArrayOfCircles *array = createArrayOfCircles(5);
    printf("Друкування масиву:\n\n");
    printArrayOfCircles(array);

    setCircleAtIndex(array,circle,0);
    printArrayOfCircles(array);

    setCircleAtIndex(array,circle,3);
    printArrayOfCircles(array);

    deletePoint(point1);
    deletePoint(point2);
    deleteCircle(circle);
    deleteArrayOfCircles(array);
}
