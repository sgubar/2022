#include <stdio.h>
#include "dk12_tool.h"

int main(int argc, const char *argv[])
{

	FloatList *list = createFloatList(); // create float list

	printf("\n");
	addValueToFloatList(list, 2.53); // add elements
	addValueToFloatList(list, 4.3);
	printFloatList(list); // print new list

	insertElementToFloatListAtIndex(list, 0, 0.0); // add elements in chosen place
	insertElementToFloatListAtIndex(list, 1, 54.2);
	insertElementToFloatListAtIndex(list, 2, 97.2);
	insertElementToFloatListAtIndex(list, 3, -15.43);
	insertElementToFloatListAtIndex(list, 4, 57.99);
	printFloatList(list);

	removeFirstElementFromFloatList(list); // remove first element
	printFloatList(list);
	removeElementFromFloatListAtIndex(list, 3); // remove element from chosen place
	printFloatList(list);
	removeLastElementFromFloatList(list); // remove last element
	printFloatList(list);

	deleteFloatList(list); // delete float list
	return 0;
}
