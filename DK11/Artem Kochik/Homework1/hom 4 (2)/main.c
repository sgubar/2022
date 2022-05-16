#include <stdio.h>
#include "dk11_tool.h"

int main(int argc, const char * argv[]) {
	DoubleList *list = createDoubleList();

	printDoubleList(list);

	addValueToDoubleList(list, 12.56);
	printDoubleList(list);

    insertElementToDoubleListAtIndex(list, 1, 40.0);
    insertElementToDoubleListAtIndex(list, 2, 62.2);

	addValueToDoubleList(list, 101.1);
	printDoubleList(list);

	removeFirstElementFromDoubleList(list);
	printDoubleList(list);

    removeElementFromDoubleListAtIndex(list, 2);

	removeLastElementFromDoubleList(list);
	printDoubleList(list);

	deleteDoubleList(list);
	return 0;
}
