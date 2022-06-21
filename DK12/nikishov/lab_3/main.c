#include <stdio.h>
#include "tree.h"

int main(void)
{
	ShortTree *tree = createShortTree();
	insertShortValueToTree(tree, (short)'A');
	insertShortValueToTree(tree, (short)'F');
	insertShortValueToTree(tree, (short)'Z');
	printTree(tree);

	destroyShortTree(tree);
	
	return 0;
}
