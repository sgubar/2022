#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mod2.h"


int main()
{    
    printPromptRec();

    Point *myPoint1 = createPoint("pt1");
    Point *myPoint2 = createPoint("pt2");
    
    if (!checkPoints(myPoint1, myPoint2)) {
        printf("error. please check the coordinates.\n");
        exit(EXIT_FAILURE);
    }
    
    Rectangle *myRec = createRectangle(myPoint1, myPoint2);    

    printf("area: %lf\n", calculateArea(myRec));

    deletePoint(myPoint1);
    deletePoint(myPoint2);
    deleteRectangle(myRec);

    return 0;
   
}

