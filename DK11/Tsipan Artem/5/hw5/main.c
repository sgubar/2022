#include <stdio.h>
#include "treeofint.h"

int main() {
	IntTree *inttree = createIntTree();

	insertIntValueToTree(inttree,85);
	insertIntValueToTree(inttree,6);
	insertIntValueToTree(inttree,89);
	insertIntValueToTree(inttree,34);
	insertIntValueToTree(inttree,61);
	insertIntValueToTree(inttree,7);
	insertIntValueToTree(inttree,25);
	insertIntValueToTree(inttree,65);
	printTree(inttree);

	deleteNodeWithValue(inttree,65);
	printTree(inttree);

	destroyIntTree(inttree);
}
