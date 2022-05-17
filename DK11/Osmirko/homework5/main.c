#include <stdio.h>
#include "dk11_tool.h"

int main(int argc, const char * argv[])
{
	TreePtr tree = createTree();
	
	insertNode(tree, "abc");
	insertNode(tree, "abcd");
	insertNode(tree, "ab");
	insertNode(tree, "a");

    printTree(tree);

    NodePtr theFindNode = findNode(tree, "abc");
    printf("\nFind result: %x\n", (unsigned int)theFindNode);
    
    deleteNode(tree, "a");

    printTree(tree);

    destroyTree(tree);
	
	return 0;
}
