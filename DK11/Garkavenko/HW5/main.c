#include <stdio.h>
#include "tree.h"

int main() {
	DoubleTree *tree = createDoubleTree();
	insertDoubleValueToTree(tree,27);
	insertDoubleValueToTree(tree,46);
	insertDoubleValueToTree(tree,58);
	insertDoubleValueToTree(tree,24);
	insertDoubleValueToTree(tree,49);
	insertDoubleValueToTree(tree,3);
	insertDoubleValueToTree(tree,99);
	insertDoubleValueToTree(tree,77);
	printTree(tree);
	deleteNodeWithValue(tree,77);
	printTree(tree);
	destroyDoubleTree(tree);
}
