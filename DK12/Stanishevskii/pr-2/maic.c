#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tree_dk12.h"
#define MAXSIZE 20

int main(int argc, char** argv) {
	srand(time(NULL));

	BinTree* ATree = createTree();

	debugTree(ATree);

	printf("Tree output\n\n");

	printTree(ATree->root);

	if (NULL != findNode(ATree, 10)) {
		printf("\nRequired node %d\n\n", findNode(ATree, 10)->value);
	} else
		printf("\nNode isn't found\n\n");

	deleteValueFromTheTree(ATree, 10);

	printTree(ATree->root);

	if (NULL != findNode(ATree, 10)) {
		printf("\nRequired node %d\n\n", findNode(ATree, 10)->value);
	} else
		printf("\nNode isn't found\n\n");

	addNode(ATree, 5);

	printTree(ATree->root);

	if (NULL != findNode(ATree, 10)) {
		printf("\nRequired node %d\n\n", findNode(ATree, 10)->value);
	} else
		printf("\nNode isn't found\n\n");

	destroyTree(ATree);
	return 0;
}
