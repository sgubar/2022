#include <stdio.h>
#include "dk11_tool.h"

int main()
{
	TreePtr tree = createTree();
	
	insertNode(tree, "Imerius");
	insertNode(tree, "Diablo");
	insertNode(tree, "DK");
	insertNode(tree, "D.Va");
    printTree(tree);

    NodePtr findHero = findNode(tree, "Imerius");
    printf("\nFind hero in: %x\n", (unsigned int)findHero);
    
    deleteNode(tree, "Diablo");

    printTree(tree);
    destroyTree(tree);
	
	return 1;
}
