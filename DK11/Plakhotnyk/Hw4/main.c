#include <stdio.h>
#include "tool.h"

int main(int argc, const char *argv[])
{

    List *list = createList();

    printf("\n");
    addValueToList(list, 5.04);
    addValueToList(list, 0.13);
    printList(list);

    insertElementToListAtIndex(list, 0, 12.0);
    insertElementToListAtIndex(list, 1, 4.5);
    insertElementToListAtIndex(list, 2, 9.01);
    insertElementToListAtIndex(list, 3, -1.4);
    insertElementToListAtIndex(list, 4, -21.9);
    printList(list);

    removeFirstElementFromList(list);
    printList(list);
    removeElementFromListAtIndex(list, 3);
    printList(list);
    removeLastElementFromList(list);
    printList(list);

    deleteList(list);
    return 0;
}
