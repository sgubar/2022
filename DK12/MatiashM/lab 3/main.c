#include <stdio.h>
#include "tools.h"

int main()
{
	TreePtr tree = createTree();
	
	insertNode(tree, "element");
	insertNode(tree, "el");
	insertNode(tree, "elem");
	insertNode(tree, "e");
    printTree(tree);

    NodePtr findElem = findNode(tree, "elem");
    printf("\nFind element in: %x\n", (unsigned int)findElem);
    
    deleteNode(tree, "elem");

    printTree(tree);
    destroyTree(tree);
	
	return 0;
}