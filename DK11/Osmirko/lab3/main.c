#include <stdio.h>
#include "dk11_tool.h"

int main(int argc, const char * argv[])
{
	TreePtr tree = createTree();
	
	insertNode(tree, "plane");
	insertNode(tree, "wizard");
	insertNode(tree, "ghost");
	insertNode(tree, "book");

    printTree(tree);

    NodePtr theFindNode = findNode(tree, "plane");
    printf("\nFind result: %x\n", (unsigned int)theFindNode);
    
    deleteNode(tree, "book");

    printTree(tree);

    destroyTree(tree);
	
	return 0;
}
