#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
    SingleList *list = createSingleList();

    printSingleList(list);

    addFloatValueToSingleList(list, 2.1);
    printSingleList(list);

    insertFloatElementToSingleListByIndex(list, 1.2, 1);
    printSingleList(list);

    removeFirsElementFromSingleList(list);
    printSingleList(list);

    removeLastElementFromSingleList(list);
    printSingleList(list);

    deletSingleList(list);
}
