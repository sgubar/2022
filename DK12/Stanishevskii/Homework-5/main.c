#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "dk_tool.h"

int main()
{
	doubleTree* tree = createDoubleTree();
	insertValue(tree, 2.832);
	insertValue(tree, 5.123);
	insertValue(tree, 1.952);
	insertValue(tree, 5.923);
	insertValue(tree, 7.364);
	insertValue(tree, 5.634);
	insertValue(tree, 9.227);
	insertValue(tree, 1.086);

	printf("Case: ");
	printTree(tree->root);
	printf("\nNode %.3f\n", FindNodeValue(tree, 7.364)->value);

	deleteValue(tree, 5.923);
	deleteValue(tree, 5.634);

	printTree(tree->root);
	printf("\nNode %.3f is still here", FindNodeValue(tree, 7.364)->value);

	deleteDoubleTree(tree);
}
