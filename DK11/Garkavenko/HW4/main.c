#include "single_list.h"

int main()
{
    CharSingleList *list = createCharSingleList();

    printCharSingleList(list);

    addCharValueToSingleList(list, 5);

    addCharValueToSingleList(list, 2);
    printCharSingleList(list);

    removeFirstElementFromCharSingleList(list);
    printCharSingleList(list);

    removeLastElementFromCharSingleList(list);
    printCharSingleList(list);

    printf("Hello world!\n");

    deleteCharSingleList(list);
    return 0;
}
