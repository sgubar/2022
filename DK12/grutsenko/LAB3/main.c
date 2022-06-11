#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"

int main()
{
	IntTree *tree = createTree_Int();
	
    insertNodeToTree_Int(tree, 8);
    insertNodeToTree_Int(tree, 3);
    insertNodeToTree_Int(tree, 5);
    insertNodeToTree_Int(tree, 4);
    insertNodeToTree_Int(tree, 2);
	insertNodeToTree_Int(tree, 9);
	insertNodeToTree_Int(tree, 20);
    insertNodeToTree_Int(tree, 21);


    printf("\nroot: %d\n", tree->root->data);

    IntNode *unknown = findNodeByValue_Int(tree, 3);
    printf("unknown: %d\n", unknown->data);

    deleteNodeByValue_Int(tree, 9);

    printf("tree:\n");
    printTree_Int(tree->root);
    destroyTree_Int(tree);
	
	return 1;
}