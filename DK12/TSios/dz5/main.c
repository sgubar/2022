#include <stdio.h>
#include "tool.h"

int main()
{
    TreePtr tree = createTree();

    insertNode(tree, "rtyfuhj");
    insertNode(tree, "vhgj");
    insertNode(tree, "jgkgify");
    insertNode(tree, "mgd");
    printTree(tree);

    NodePtr findEl = findNode(tree, "jgkgify");
    printf("\nFind element in: %x\n", (unsigned int)findEl);

    deleteNode(tree, "jgkgify");

    printTree(tree);
    destroyTree(tree);

    return 0;
}
