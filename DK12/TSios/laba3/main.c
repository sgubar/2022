#include <stdio.h>
#include "tools.h"

int main()
{
    TreePtr tree = createTree();

    insertNode(tree, 234.6);
    insertNode(tree, 1.64);
    insertNode(tree, -56);
    insertNode(tree, 6.897);
    printTree(tree);

    NodePtr findNumber = findNode(tree, -56);
    printf("\nFind number in: %x\n", (unsigned int)findNumber);

    deleteNode(tree, -56);

    printTree(tree);
    destroyTree(tree);

    return 1;
}
