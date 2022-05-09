#include <stdio.h>
#include "tree.h"

int main() {
	FloatTree *tree = createFloatTree();
	insertFloatValueToTree(tree, 3.456781);
	insertFloatValueToTree(tree, 3.678393);
	insertFloatValueToTree(tree, 14.5897);
	insertFloatValueToTree(tree, 9.3);
	insertFloatValueToTree(tree, 2);
	insertFloatValueToTree(tree, 4.3);
	printTree(tree);
	printf("new tree:\n");
	deleteNodeWithValue(tree, 4.3);
	printTree(tree);
  destroyFloatTree(tree);
	printf("Hello, World!\n");
	return 0;
}
