#include "single_list.h"

int main()
{
    FloatSingleList *list = createFloatSingleList();

    printFloatSingleList(list);

    addFloatValueToSingleList(list, 5.867448);



    addFloatValueToSingleList(list, 2.237897);
    printFloatSingleList(list);

    removeFirstElementFromFloatSingleList(list);
    printFloatSingleList(list);

    removeLastElementFromFloatSingleList(list);
    printFloatSingleList(list);

    printf("Hello world!\n");

    deleteFloatSingleList(list);
    return 0;
}
