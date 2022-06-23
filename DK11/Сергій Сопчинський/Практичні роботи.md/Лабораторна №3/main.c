#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"

int main()
{
	IntTree *tree = createTree_Int();
   	insertNodeToTree_Int(tree, 33);
   	insertNodeToTree_Int(tree, 12);
   	insertNodeToTree_Int(tree, 11);
   	insertNodeToTree_Int(tree, 6);
   	insertNodeToTree_Int(tree, 1);
	insertNodeToTree_Int(tree, 22);
	insertNodeToTree_Int(tree, 19);
   	insertNodeToTree_Int(tree, 20);

	printf("\nroot: %d\n", tree->root->data);
  	IntNode *unknown = findNodeByValue_Int(tree, 11);
   	printf("unknown: %d\n", unknown->data);
   	deleteNodeByValue_Int(tree, 22);
	printf("tree:\n");
    	printTree_Int(tree->root);
    	destroyTree_Int(tree);
	return 1;
}
