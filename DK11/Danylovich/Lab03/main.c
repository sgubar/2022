#include <stdio.h>
#include "floattree.h"

int main() {
	FloatTree *tree = createFloatTree();
	insertFloatValueToTree(tree,27.2);
	insertFloatValueToTree(tree,46.44);
	insertFloatValueToTree(tree,58.21);
	insertFloatValueToTree(tree,24.87);
	insertFloatValueToTree(tree,49.563);
	insertFloatValueToTree(tree,3.54);
	insertFloatValueToTree(tree,99.24);
	insertFloatValueToTree(tree,77.76);
	printTree(tree);
	deleteNodeWithValue(tree,49.563);
	printTree(tree);
	destroyFloatTree(tree);
}
