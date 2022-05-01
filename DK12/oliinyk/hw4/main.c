#include <stdio.h>
#include "dk12_tool.h"

int main(int argc, const char * argv[]) {
	DoubleList *list = createDoubleList();

	printDoubleList(list);

	addValueToDoubleList(list, 4.56);
	printDoubleList(list);

    insertElementToDoubleListAtIndex(list, 1, 32.0);
    insertElementToDoubleListAtIndex(list, 2, 54.2);

	addValueToDoubleList(list, 93.1);
	printDoubleList(list);

	removeFirstElementFromDoubleList(list);
	printDoubleList(list);

    removeElementFromDoubleListAtIndex(list, 2);

	removeLastElementFromDoubleList(list);
	printDoubleList(list);

	deleteDoubleList(list);
	return 0;
}