#include <stdio.h>
#include "tools.h"

int main(int argc, const char *argv[])
{
    FloatList *list = createFloatList();

    printFloatList(list);

    addValueToFloatList(list, 1.6);
    printFloatList(list);

    insertElementToFloatListAtIndex(list, 1, 12.756);
    insertElementToFloatListAtIndex(list, 2, 54.2);

    addValueToFloatList(list, 233.06);
    printFloatList(list);

    removeFirstElementFromFloatList(list);
    printFloatList(list);

    removeElementFromFloatListAtIndex(list, 2);

    removeLastElementFromFloatList(list);
    printFloatList(list);

    deleteFloatList(list);
    return 0;
}