#include "dk12_tool.c"
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
#include <math.h>

// эллипс 

int main(void) {
	Point *center = createPoint(3, 2); 
	Point *edge_a = createPoint(1, 4);
	Point *edge_b = createPoint(6, 5);
	Elips *elipsOne = createElips(center, edge_a, edge_b);

    Elips *elipsTwo = createElipsXY(0, 0, 0, 5, 2, 0);

	Point *array[3];
    array[0] = createPoint(-25, 0);
    array[1] = createPoint(-25, 2);
    array[2] = createPoint(0, 0);
	Elips *elipsThree = createArrElips(array);

    Elips *arrayElips[3] = {elipsOne, elipsTwo, elipsThree};

//===========================================================================================================================//
// 2-га частина
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
    // empty so print nothing

    index2 = setElipsAtIndex(elipsArray, elipsThree , 2);

    printDetailElips(getElipsByIndex(elipsArray, 2));

    printf("Arrays: %d\n\n", countElipsArray(elipsArray));
   
    printElipsArray(elipsArray);

    deleteElipsArray(elipsArray);
//===========================================================================================================================//
	return 1;
}
// в этом методе мы строим фигуру по трём точкам: center - центр эллипса, edge_a - крайняя точка первой полуоси, edge_b - крайняя точка второй полуоси
// точки должны быть построены так: если от center к edge_a и edge_b провести линии - эти линии будут перпендикулярны, только так получается эллипс
    printf("Three: %d\n", index2);
    printf("Four: %d\n", index3);

    printDetailElips(getElipsAtIndex(elipsArray, 2));

    index2 = setElipsAtIndex(elipsArray, elipsThree, 2);

    printDetailElips(getElipsAtIndex(elipsArray, 2));

    printf("Array count: %d\n\n", countElipsArray(elipsArray));
   
    printElipsArray(elipsArray);

    deleteElipsArray(elipsArray);
//===========================================================================================================================//
	return 1;
}
