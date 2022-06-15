#include "inttree.h"

int main() {
	IntTree *tree = createIntTree();

	insertIntValueToTree(tree,51);
	insertIntValueToTree(tree,74);
	insertIntValueToTree(tree,21);
	insertIntValueToTree(tree,84);
	insertIntValueToTree(tree,43);
	insertIntValueToTree(tree,9);
	insertIntValueToTree(tree,29);
	insertIntValueToTree(tree,13);
	printTree(tree);

	deleteNodeWithValue(tree,13);
	printTree(tree);
    
	destroyIntTree(tree);
}
