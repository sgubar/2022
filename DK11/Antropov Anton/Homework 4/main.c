#include "singlelist.h"

int main(int argc, const char * argv[]) {

	IntSingleList *singlelist = createIntSingleList();
	printIntSingleList(singlelist);

	addIntValueToIntSingleList(singlelist, 44);
	printIntSingleList(singlelist);

	addIntValueToIntSingleList(singlelist, 89);
	printIntSingleList(singlelist);

	removeFirstElementFromIntSingleList(singlelist);
	printIntSingleList(singlelist);

	removeLastElementFromIntSingleList(singlelist);
	printIntSingleList(singlelist);

    deleteIntSingleList(singlelist);
}
