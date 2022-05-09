#include <stdio.h>
#include "inttree.h"

int main() {
	IntTree *tree = createIntTree();
	insertIntValueToTree(tree,27);
	insertIntValueToTree(tree,46);
	insertIntValueToTree(tree,58);
	insertIntValueToTree(tree,24);
	insertIntValueToTree(tree,49);
	insertIntValueToTree(tree,3);
	insertIntValueToTree(tree,99);
	insertIntValueToTree(tree,77);
	printTree(tree);
	deleteNodeWithValue(tree,77);
	printTree(tree);
	destroyIntTree(tree);
}
