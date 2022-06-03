#include <stdio.h>
#include "tools.h"

int main()
{
	TreePtr tree = createTree();
	
	insertNode(tree, 5);
	insertNode(tree, 1);
	insertNode(tree, 8);
	insertNode(tree, 0);
    printTree(tree);

    NodePtr findNum = findNode(tree, 0);
    printf("\nFind number in: %x\n", (unsigned int)findNum);
    
    deleteNode(tree, 0);

    printTree(tree);
    destroyTree(tree);
	
	return 0;
}