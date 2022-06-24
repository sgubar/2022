#include <stdio.h>
#include "dk12_tool.h"


int main() {
	List *list = createWordsList();

	addNodeToWordsList(list, "vxcvxcbzv");
    addNodeToWordsList(list, "fgbdf");
    addNodeToWordsList(list, "bxv");
    addNodeToWordsList(list, "dsbnb");
    addNodeToWordsList(list, "q");
    addNodeToWordsList(list, "sfn");

	printWordsList(list);

	sortWords(list);
    
	printWordsList(list);

	destroyWordsList(list);
	return 1;
}