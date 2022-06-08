#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"

int main()
{
	FloatTree *tree = createTree_Float();
	
	insertNodeToTree_Float(tree, 8.23);
	insertNodeToTree_Float(tree, 3.4);
    insertNodeToTree_Float(tree, 3.3);
    insertNodeToTree_Float(tree, 3.7);
    insertNodeToTree_Float(tree, 3.35);
	insertNodeToTree_Float(tree, 9.567);
	insertNodeToTree_Float(tree, 14.2);
    insertNodeToTree_Float(tree, 14.1);


    printf("\nroot: %f\n", tree->root->data);

    FloatNode *unknown = findNodeByValue_Float(tree, 3.4);
    printf("unknown: %f\n", unknown->data);

    deleteNodeByValue_Float(tree, 9.567);

    printf("tree:\n");
    printTree_Float(tree->root);
    destroyTree_Float(tree);
	
	return 1;
}