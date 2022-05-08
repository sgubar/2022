#include <stdio.h>
#include "dk12_tool.h"

int main(int argc, const char * argv[]) {
	intList *list = createintList();

	printintList(list);

	addValueTointList(list, 7);
	printintList(list);

    insertElementTointListAtIndex(list, 1, 44);
    insertElementTointListAtIndex(list, 2, 28);

	addValueTointList(list, 59);
	printintList(list);

	removeFirstElementFromintList(list);
	printintList(list);

    removeElementFromintListAtIndex(list, 2);

	removeLastElementFromintList(list);
	printintList(list);

	deleteintList(list);
	return 0;
}
