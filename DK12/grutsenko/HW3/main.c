#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "rec.h"
#include "recArray.h"


int main()
{   printf("Enter rec\n");
    Point *myPoint1 = createPoint("pt1");
    Point *myPoint2 = createPoint("pt2");
    printf("Enter rec\n");
    Point *myPoint3 = createPoint("pt1");
    Point *myPoint4 = createPoint("pt2");
    
    if (!checkPoints(myPoint1, myPoint2)
    ||  !checkPoints(myPoint3, myPoint4)) {
        printf("error. please check the coordinates.\n");
        exit(EXIT_FAILURE);
    }
    
    Rectangle *myRec1 = createRectangle(myPoint1, myPoint2);
    Rectangle *myRec2 = createRectangle(myPoint3, myPoint4);

    ArrayRectangle *myArray = createArrayRectangle(3);

    int bestRec = addRectangleToArray(myArray, myRec1);
    int worstRec = addRectangleToArray(myArray, myRec2);
    int beautifulRec = addRectangleToArray(myArray, myRec1);
    int amazingRec = addRectangleToArray(myArray, myRec2);

    printArrayRectangle(myArray);

    deleteArrayRectangle(myArray);

    return 0;
   
}
