#include <stdio.h>
#include "tree.h"

int main() {
	IntTree *tree = createIntTree();
	insertIntValueToTree(tree, 5);
	insertIntValueToTree(tree, 10);
	insertIntValueToTree(tree, 18);
	insertIntValueToTree(tree, 7);
	insertIntValueToTree(tree, 2);
	insertIntValueToTree(tree, 4);
	printTree(tree);

	printf("new tree:\n");
	deleteNodeWithValue(tree, 4);
	printTree(tree);

	destroyIntTree(tree);

	return 0;
}
