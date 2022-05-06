#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"

int main()
{
    List* list = createList();

    addElement(list, 10);
    addElement(list, 20);
    addElement(list, 30);
    printList(list);

    replaceElement(list, 0, 50);
    replaceElement(list, 1, 60);
    replaceElement(list, 3, 20);
    printList(list);

    insertElement(list, 0, 999);
    insertElement(list, 3, 999);
    insertElement(list, 6, 999);
    printList(list);
}