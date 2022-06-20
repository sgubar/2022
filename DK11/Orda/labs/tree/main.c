#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

int main()
{
    treePtr tree = createTree();

    insertNode(tree, "Diffindo");
    insertNode(tree, "Engorgio");
    insertNode(tree, "Accio");
    insertNode(tree, "Finite");
    insertNode(tree, "Expecto");

    displayTree(tree);

    nodePtr anode = findNode(tree, "Accio");
    printf("\nNode: %p\n", anode);

    deleteNodeWithData(tree, "Accio");

    displayTree(tree);

    deleteTree(tree);
}
