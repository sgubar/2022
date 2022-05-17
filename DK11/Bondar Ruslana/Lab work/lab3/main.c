#include <stdio.h>
#include "tree.h"

int main() {
	IntTree *tree = createIntTree();
	insertIntValueToTree(tree, 3);
	insertIntValueToTree(tree, 1);
	insertIntValueToTree(tree, 14);
	insertIntValueToTree(tree, 9);
	insertIntValueToTree(tree, 2);
	insertIntValueToTree(tree, 4);
	printTree(tree);
	printf("new tree:\n");
	deleteNodeWithValue(tree, 4);
	printTree(tree);

	destroyIntTree(tree);

	// insert code here...
	printf("Hello, World!\n");
	return 0;
}
