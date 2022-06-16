#include <stdio.h>
#include "single_list.h"

int main() {
    ListSingleFloat *cheese = createListSingleFloat();
    addValueTo_ListSingleFloat(cheese, 7.456);
    addValueTo_ListSingleFloat(cheese, 2.22);
    addValueTo_ListSingleFloat(cheese, -12.009);
    addValueTo_ListSingleFloat(cheese, 55.8);
    addValueTo_ListSingleFloat(cheese, 3);
    printListSingleFloat(cheese);
    printf("number of elements in the list: %d", getSize_ListSingleFloat(cheese)); //5

    printf("\n");  
    
    addValueTo_ListSingleFloat_atIndex(cheese, 0, 2);
    addValueTo_ListSingleFloat_atIndex(cheese, 8888, 7); //invalid
    printListSingleFloat(cheese);
    printf("number of elements in the list: %d", getSize_ListSingleFloat(cheese)); //6

    printf("\n");

    deletefromList_NodeSingleFloat_atIndex(cheese, 6); //invalid
    deleteFromList_NodeSingleFloat_byValue(cheese, 2.22);
    deletefromList_NodeSingleFloat_atIndex(cheese, 3);
    printListSingleFloat(cheese);
    printf("number of elements in the list: %d", getSize_ListSingleFloat(cheese)); //4

    deleteListSingleFloat(cheese);

    return 0;
}
