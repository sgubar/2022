#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"

int main()
{
    List* list = createList();

    inputElement(list);
    printList(list);

    delAvgElement(list);
    printList(list);

    deleteList(list);
}